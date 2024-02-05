#include "infotreff.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <json.hpp>
#include <sstream>
#define print(x) cout << x << endl;

using namespace std;
using namespace nlohmann;
auto NR = "artikelnummer";
auto MENG = "menge";
InfoTreff::InfoTreff() {}

bool InfoTreff::benutzerDialog() {
  bool run = true;
  do {
    cout << "InfoTreff-Management" << endl;
    print("1: Wareneingaenge einlesen");
    print("2: Tagesverkaeufe einlesen");
    print("3: Bestandliste ausgeben");
    print("4: Umsatzuebersicht");
    print("0: Exit");
    int input;
    cin >> input;
    switch (input) {
    case 1:
      warenEingaengeLesen();
      break;
    case 2:
      verkaeufeLesen();
      break;
    case 3:
      bestandsListeAusgeben();
      break;
    case 4:
      umsatzberechnen();
      break;
    case 0:
      run = false;
      break;
    default:
      break;
    }
  } while (run);
}

bool InfoTreff::verkaeufeLesen() {
  ifstream file("/Users/tuandl/Studium "
                "Hda/PG2/PG2_Malcherek/"
                "build-Infotreff_Cafe-Qt_6_6_0_for_macOS-Debug/verkaeufe.txt");
  string line;
  getline(file, line);

  string date = line;
  int day = stoi(date.substr(6, 2));
  int year = stoi(date.substr(0, 4));
  int month = stoi(date.substr(4, 2));
  Datum datum(day, month, year);
  while (!file.eof()) {
    stringstream ss;
    getline(file, line);
    ss << line;
    while (!ss.eof()) {
      string temp1, temp2;
      getline(ss, temp1, '|');
      getline(ss, temp2, '|');
      auto nr = stol(temp1);
      auto menge = stod(temp2);
      auto neueVerkauf = make_shared<Verkauf>(nr, menge, datum);
      auto artikel = artikelListe[nr];
      verkaeufe.push_back(neueVerkauf);
      if (auto inf = dynamic_pointer_cast<InfoTreffArtikel>(artikel))
        for (auto &z : inf->getZutaten()) {
          if (bestandsListe[nr] >= z.menge * menge)
            bestandsListe[nr] -= z.menge * menge;
          else
            bestandsListe[nr] = 0;
        }
      else if (auto handl = dynamic_pointer_cast<HandelsArtikel>(artikel)) {
        if (bestandsListe[nr] >= menge)
          bestandsListe[nr] -= menge;
        else
          bestandsListe[nr] = 0;
      }
    }
  }
}

bool InfoTreff::warenEingaengeLesen() {
  ifstream file(
      "/Users/tuandl/Studium "
      "Hda/PG2/PG2_Malcherek/build-Infotreff_Cafe-Qt_6_6_0_for_macOS-Debug/"
      "wareneingaenge.json");
  json fileContent = json::parse(file);

  string date = fileContent["datum"];
  int day = stoi(date.substr(6, 2));
  int year = stoi(date.substr(0, 4));
  int month = stoi(date.substr(4, 2));

  Datum datum(day, month, year);
  auto eingaenge = fileContent["wareneingaenge"];

  for (const auto &e : eingaenge) {
    auto neueWare = make_shared<WarenEingang>(e[NR], e[MENG], datum);
    warenEingaenge.push_back(neueWare);
    bestandsListe[e[NR]] += (double)e[MENG];
  }
}

void InfoTreff::bestandsListeAusgeben() {
  print("Sortierung nach");
  print("1: Artikelnummer");
  print("2: Artikelname");
  print("3: Bestandsmenge");
  int input;
  cin >> input;
  vector<pair<long, double>> toSort;
  for (const auto &b : bestandsListe) {
    toSort.push_back(b);
  }
  switch (input) {
  case 1:
    sort(toSort.begin(), toSort.end(),
         [this](pair<long, double> x, pair<long, double> y) {
           return artikelListe[x.first]->getArtikelNummer() <
                  artikelListe[y.first]->getArtikelNummer();
         });
    break;
  case 2:
    sort(toSort.begin(), toSort.end(),
         [this](pair<long, double> x, pair<long, double> y) {
           return artikelListe[x.first]->getArtikelName() <
                  artikelListe[y.first]->getArtikelName();
         });
    break;
  case 3:
    sort(toSort.begin(), toSort.end(),
         [](pair<long, double> x, pair<long, double> y) {
           return x.second < y.second;
         });
    break;
  default:
    break;
  }
  cout << setw(10) << left << "Nummer" << setw(30) << "Name" << setw(6)
       << "Menge" << setw(10) << "Einheit" << endl;

  for (const auto &b : toSort) {
    cout << setw(10) << left << b.first << setw(30)
         << artikelListe[b.first]->getArtikelName() << setw(6) << b.second
         << setw(10) << artikelListe[b.first]->getEinheit() << endl;
  }
}

void InfoTreff::umsatzberechnen() {


  for (const auto &v : verkaeufe) {
    Umsatz u;
    auto artikel = artikelListe[v->getArtikelNummer()];
    if (auto inf = dynamic_pointer_cast<InfoTreffArtikel>(artikel))
      u.value = inf->getVerkaufsPreis() * v->getMenge();

    else if (auto handl = dynamic_pointer_cast<HandelsArtikel>(artikel))
      u.value = handl->getVerkaufsPreis() * v->getMenge();
    gesamtUmsatz += u.value;
    u.nr = v->getArtikelNummer();
    u.name = artikelListe[v->getArtikelNummer()]->getArtikelName();
    umsatzList.push_back(u);
  }


  sort(umsatzList.begin(),umsatzList.end(),[](Umsatz x, Umsatz y){
      return x.value > y.value;
  });
  cout << setw(7) << left << "Nummer" << setw(30) << "Name" << setw(10)
       << "Umsatz" << setw(15) << "Anteil" << setw(15) << left <<"Anteil kum." << setw(30) << "Kat" << endl;
  double kum = 0.0;
  for (auto &&u : umsatzList){
    u.anteil = u.value / gesamtUmsatz;
    kum += u.anteil;
    u.anteilKum = kum + u.anteil;
    if(u.anteilKum < 0.8)
      u.kat = "A";
    else if(u.anteilKum > 0.9)
      u.kat = "C";
    else u.kat = "B";
    cout << setw(7) << left << u.nr << setw(30) << u.name << setw(10)
         << u.value << setw(15) << u.anteil << setw(15) << left<< u.anteilKum << setw(30) << u.kat<< endl;
  }




}
