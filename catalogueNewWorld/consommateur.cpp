#include "consommateur.h"
#include <iostream>
#include <QDebug>

Consommateur::Consommateur()
{

}

Consommateur::Consommateur(string nom, string prenom, string mail)
{
    qDebug() << "Consommateur::Consommateur(string nom, string prenom, string mail)";
    this->nom = nom;
    this->prenom = prenom;
    this->mail = mail;
}
string Consommateur::getNom() const
{
    return nom;
}

string Consommateur::getPrenom() const
{
    return prenom;
}

string Consommateur::getMail() const
{
    return mail;
}


