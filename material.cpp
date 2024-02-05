#include "material.h"


Material::Material(long artikelNummer, const std::string &einheit, const std::string &artikelName, double einkaufsPreis) : Artikel(artikelNummer, einheit, artikelName),
    einkaufsPreis(einkaufsPreis)
{}

double Material::getEinkaufsPreis() const
{
    return einkaufsPreis;
}
