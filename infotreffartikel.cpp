#include "infotreffartikel.h"


InfoTreffArtikel::InfoTreffArtikel(long artikelNummer, const std::string &einheit, const std::string &artikelName, double verkaufsPreis, const std::vector<Zutat> &zutaten) : Artikel(artikelNummer, einheit, artikelName),
    verkaufsPreis(verkaufsPreis),
    zutaten(zutaten)
{}

double InfoTreffArtikel::getVerkaufsPreis() const
{
    return verkaufsPreis;
}

std::vector<Zutat> InfoTreffArtikel::getZutaten() const
{
    return zutaten;
}
