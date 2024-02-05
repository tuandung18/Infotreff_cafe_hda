#ifndef WARENEINGANG_H
#define WARENEINGANG_H
#include "datum.h"
//#include <QDate>

class WarenEingang
{
public:
    WarenEingang(long artikelNummer, double menge, const Datum &datum);


private:
    long artikelNummer;
    double menge;
    Datum datum;
   // QDate Datum;
};

#endif // WARENEINGANG_H
