#ifndef CONSOMMATEUR_H
#define CONSOMMATEUR_H
#include <string>
using namespace std;

class Consommateur
{
public:
    Consommateur();
    Consommateur(string nom, string prenom, string mail);

    string getNom() const;

    string getPrenom() const;

    string getMail() const;

private:
    string nom, prenom, mail;
};

#endif // CONSOMMATEUR_H
