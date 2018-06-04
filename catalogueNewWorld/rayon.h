#include "variete.h"
#ifndef RAYON_H
#define RAYON_H

#include <string>
#include <vector>
#include <iostream>
#include "template.h"

using namespace std;

class Rayon
{
public:
    Rayon();
    Rayon(int id, QString nom);
    QString toString();
    vector<Variete> *getLesVarietes();
private:
    void chargerVarietes();

    QString nom;
    vector<Variete> lesVarietes;
    int id;
    HtmlTemplate temp;
};

#endif // RAYON_H
