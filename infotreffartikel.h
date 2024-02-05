#ifndef INFOTREFFARTIKEL_H
#define INFOTREFFARTIKEL_H

#include "artikel.h"
#include <vector>
//#include <QVector>

struct Zutat{
    long artikelNummer;
    double menge;
};

class InfoTreffArtikel : public Artikel
{
public:
    InfoTreffArtikel(long artikelNummer, const std::string &einheit, const std::string &artikelName, double verkaufsPreis, const std::vector<Zutat> &zutaten);


    double getVerkaufsPreis() const;
    std::vector<Zutat> getZutaten() const;

private:
    double verkaufsPreis;
    std::vector<Zutat> zutaten;
    //QVector<Zutat> zutaten;
};

#endif // INFOTREFFARTIKEL_H
