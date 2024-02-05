#ifndef HANDELSARTIKEL_H
#define HANDELSARTIKEL_H

#include "artikel.h"

class HandelsArtikel : public Artikel
{
public:
    HandelsArtikel(long artikelNummer, const std::string &einheit, const std::string &artikelName, double einkaufsPreis, double verkaufsPreis);


    double getEinkaufsPreis() const;
    double getVerkaufsPreis() const;

private:
    double einkaufsPreis{}, verkaufsPreis{};
};

#endif // HANDELSARTIKEL_H
