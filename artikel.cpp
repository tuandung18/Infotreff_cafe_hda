#include "artikel.h"






Artikel::Artikel(long artikelNummer, const std::string &einheit, const std::string &artikelName) : artikelNummer(artikelNummer),
    einheit(einheit),
    artikelName(artikelName)
{}

long Artikel::getArtikelNummer() const
{
    return artikelNummer;
}

std::string Artikel::getEinheit() const
{
    return einheit;
}

std::string Artikel::getArtikelName() const
{
    return artikelName;
}

Artikel::~Artikel()
{

}
