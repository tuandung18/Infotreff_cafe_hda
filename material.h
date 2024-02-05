#ifndef MATERIAL_H
#define MATERIAL_H

#include "artikel.h"

class Material : public Artikel
{
public:
    Material(long artikelNummer, const std::string &einheit, const std::string &artikelName, double einkaufsPreis);


    double getEinkaufsPreis() const;

private:
    double einkaufsPreis;
};

#endif // MATERIAL_H
