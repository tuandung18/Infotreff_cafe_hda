#ifndef VERKAUF_H
#define VERKAUF_H
#include "datum.h"
//#include <QDate>

class Verkauf
{
public:
    Verkauf(long artikelNummer, double menge, const Datum &datum);


    long getArtikelNummer() const;
    double getMenge() const;

private:
    long artikelNummer;
    double menge;
    Datum datum;
   // QDate datum;
};

#endif // VERKAUF_H
