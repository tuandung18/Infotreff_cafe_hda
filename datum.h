/*
 * File:   datum.h
 * Author: arnim
 *
 * Created on 26. November 2013, 21:42
 */

#ifndef DATUM_H
#define	DATUM_H
#include <ctime>

class Datum{
public:
    // Konstruktoren
    Datum();
    Datum(int t, int m, int j);
    Datum(const Datum&);  //Kopierkonstruktor fuer Demozwecke

    //Operatoren
    Datum& operator++();
    Datum operator++(int);
    Datum& operator=(Datum otherDatum);

    void setDatum(int t, int m, int j);
    void setzeAktuellesDatum();
    int GetJahr() const { return jahr;}
    int GetMonat() const { return monat;}
    int GetTag() const { return tag;}

private:
    int tag, monat, jahr;
};
bool istGueltigesDatum(int t, int m, int j);
bool istSchaltjahr(int jahr);
#endif	/* DATUM_H */

