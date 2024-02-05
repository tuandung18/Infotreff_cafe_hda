#include "datum.h"
#include <iostream>
using namespace std;

Datum::Datum() {
    setzeAktuellesDatum();
}

Datum::Datum(int t, int m, int j) {
    setDatum(t, m, j);
}

Datum::Datum(const Datum& datum){
    setDatum(datum.GetTag(),datum.monat,datum.GetJahr());
   // cout << "Kopierkonstruktor gerufen" << endl;
}

Datum& Datum::operator=(Datum otherDatum){
    tag = otherDatum.tag;
    monat = otherDatum.monat;
    jahr = otherDatum.jahr;
    return *this;
}

Datum& Datum::operator++(){
    ++tag;
    if (!istGueltigesDatum(tag, monat, jahr)){
        tag = 1;
        if (++monat > 12){
            monat = 1;
            ++jahr;
        }
    }
    return *this;
}

Datum Datum::operator++(int){
    Datum temp(*this);
    ++*this;
    return temp;
}

bool istSchaltjahr(int jahr){
    return ((jahr % 4 == 0 && jahr % 100 ) || jahr % 400 == 0);
}
bool istGueltigesDatum(int t, int m, int j) {
    // Tage pro Monat(static vermeidet Neuinitialisierung):
    static int tmp[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    tmp[1] = istSchaltjahr(j) ? 29 : 28;

    return m >= 1 && m <= 12
            && j >= 1583
            && t >= 1 && t <= tmp[m - 1];
}

void Datum::setzeAktuellesDatum() {
    time_t now = time(NULL); // aktuelle Zeit in s seit 1.1.1970
    tm* z = localtime(&now); // Zeiger auf eine vordefinierte Struktur des Typs tm.
    // Umwandlung mit localtime().
    jahr = z->tm_year + 1900;
    monat = z->tm_mon + 1; // localtime() liefert 0..11
    tag = z->tm_mday;
}

void Datum::setDatum(int t, int m, int j) {
    if (istGueltigesDatum(t, m, j)) {
        tag = t;
        monat = m;
        jahr = j;
    }
}

