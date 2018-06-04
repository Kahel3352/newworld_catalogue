#include "passerelle.h"
#ifndef VARIETE_H
#define VARIETE_H
#include <string>
#include "template.h"

using namespace std;

class Variete
{
public:
    Variete(QString nom, QString description, QString image, QString nomProduit, int qte, float prix, QString nomProducteur, QString label);
    //string toString();
    QString toString();
private:
    QString nom;
    QString description;
    QString image;
    QString nomProduit;
    int qte;
    float prix;
    QString nomProducteur;
    QString label;
    HtmlTemplate temp;
};

#endif // VARIETE_H
