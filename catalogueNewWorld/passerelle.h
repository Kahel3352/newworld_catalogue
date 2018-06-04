#include "consommateur.h"
#ifndef PASSERELLE_H
#define PASSERELLE_H
#include <vector>
#include <QtSql>
#include <iostream>
#include "rayon.h"
#include "variete.h"

using namespace std;

class Passerelle
{
public:
    /**
     * @brief Initialise la base de données
     */
    static void setDatabase();

    /**
     * @brief Charge les variété de produits à partir de la base de données
     * @return Collection des rayon qui correspondent aux points relais dans lequel le consommateur a déjà commander
     */
    static vector<Rayon> chargerRayons();

    /**
     * @brief Charge les varietes à partir de la base de données
     * @return Collection des varietes qui correspondent aux points relais du rayon
     * @param idRayon Id du rayon dont on veut charger les varietes
     */
    static vector<Variete> chargerVariete(int idRayon);

    static Consommateur chargerConsommateur();

    static QString chargerTemplate(string nom);

private:
    /**
     * @brief Base de données
     */
    static QSqlDatabase db;
    static int userId;
    static Variete test2;
};

#endif // PASSERELLE_H
