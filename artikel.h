#ifndef ARTIKEL_H
#define ARTIKEL_H
//#include <QString>
#include <string>

class Artikel
{
public:
    Artikel(long artikelNummer, const std::string &einheit, const std::string &artikelName);
    virtual ~Artikel() = 0;


    long getArtikelNummer() const;
    std::string getEinheit() const;
    std::string getArtikelName() const;

protected:
    long artikelNummer;
    std::string einheit, artikelName;
    // QString einheit, artikelName;
};

#endif // ARTIKEL_H
