#include "handelsartikel.h"


HandelsArtikel::HandelsArtikel(long artikelNummer, const std::string &einheit, const std::string &artikelName, double einkaufsPreis, double verkaufsPreis) : Artikel(artikelNummer, einheit, artikelName),
    einkaufsPreis(einkaufsPreis),
    verkaufsPreis(verkaufsPreis)
{}

double HandelsArtikel::getEinkaufsPreis() const
{
    return einkaufsPreis;
}

double HandelsArtikel::getVerkaufsPreis() const
{
    return verkaufsPreis;
}
