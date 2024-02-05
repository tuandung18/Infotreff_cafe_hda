#include "verkauf.h"


Verkauf::Verkauf(long artikelNummer, double menge, const Datum &datum) : artikelNummer(artikelNummer),
    menge(menge),
    datum(datum)
{}

long Verkauf::getArtikelNummer() const
{
    return artikelNummer;
}

double Verkauf::getMenge() const
{
    return menge;
}
