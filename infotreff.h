#ifndef INFOTREFF_H
#define INFOTREFF_H
#include <map>
#include <vector>
#include <memory>
#include "wareneingang.h"
#include "verkauf.h"
#include "artikel.h"
#include "material.h"
#include "handelsartikel.h"
#include "infotreffartikel.h"

struct Umsatz {
    long nr;
    std::string name;
    double value;
    double anteil;
    double anteilKum;
    std::string kat;
};

class InfoTreff
{
public:
    InfoTreff();
    bool benutzerDialog();
private:
    //Die Artikelliste ist bereits mit Hilfe einer Initialisierungsliste gefuellt. Hier muessen Sie also nichts mehr tun
    std::map<long, std::shared_ptr<Artikel>> artikelListe{{1, std::make_shared<HandelsArtikel>(1,"St.","Fritz Kola",0.8,1.0)},
                                                          {2, std::make_shared<Material>(2,"Kg","Hummus",10.0)},
                                                          {3, std::make_shared<InfoTreffArtikel>(3,"St.","Laugenstange belegt", 1.2,
                                                                                                 std::vector<Zutat>{{2,0.05},{4,1.0},{5,0.1},{6,0.1}})},
                                                          {4,std::make_shared<HandelsArtikel>(4,"St.","Laugenstange",0.5, 0.8)},
                                                          {5,std::make_shared<Material>(5,"Kg","Tomaten",3.0)},
                                                          {6,std::make_shared<Material>(6,"Kg","Gurke",4.5)},
                                                          {7,std::make_shared<HandelsArtikel>(7,"St.","Mars",0.5,0.8)},
                                                          {8,std::make_shared<HandelsArtikel>(8,"St.","Snickers",0.5,0.8)},
                                                          {9,std::make_shared<HandelsArtikel>(9,"St.","Twix",0.5,0.8)},
                                                          {10,std::make_shared<HandelsArtikel>(10,"St.","Bernadette Limo Zitrone",0.6,1.2)},
                                                          {11,std::make_shared<HandelsArtikel>(11,"St.","Bernadette Limo Orange",0.6,1.2)},
                                                          {12,std::make_shared<Material>(12,"Kg","Lavazza Qualita rossa",9.99)},
                                                          {13,std::make_shared<Material>(13,"L","Milch halbfett, haltbar ",0.55)},
                                                          {14, std::make_shared<InfoTreffArtikel>(14,"St.","Capuccino (Kuhmilch)", 1.5,
                                                                                                  std::vector<Zutat>{{12,0.01},{13,0.15}})},
                                                          {15,std::make_shared<Material>(15,"L","Mandelmilch",0.95)},
                                                          {16, std::make_shared<InfoTreffArtikel>(16,"St.","Capuccino (Mandelmilch)", 1.5,
                                                                                                  std::vector<Zutat>{{12,0.01},{15,0.15}})},
                                                          {17, std::make_shared<InfoTreffArtikel>(17,"St.","Espresso",0.8,
                                                                                                  std::vector<Zutat>{{12,0.01}})},
                                                          {18, std::make_shared<HandelsArtikel>(18,"St.","Club-Mate",0.7, 1.5)}
                                                          };

    // Auch die Bestandsliste ist bereits gefüllt. Das erste Argument der Map ist die Artikelnummer,
    // das zweite Argument ist die zugehörige Bestandsmenge. Es gibt also z.B. einen Bestand von Fritz Kola von 33 St.
    std::map<long, double> bestandsListe = {{1,33.0},{2,0.5},{3,0.0},{4,10.0},{5,1.0},{6,0.5},{7,30.0},{8, 7.0},{9,19.0},{10,11.0},
                                            {11,8.0},{12,1.3},{13,6.0},{14,0.0},{15,2.3},{16,0.0}};
    std::vector<std::shared_ptr<WarenEingang>> warenEingaenge;
    std::vector<std::shared_ptr<Verkauf>> verkaeufe;
    std::vector<Umsatz> umsatzList;
    double gesamtUmsatz = 0;
    bool verkaeufeLesen();
    bool warenEingaengeLesen();
    void bestandsListeAusgeben();
    void umsatzberechnen();
};

#endif // INFOTREFF_H
