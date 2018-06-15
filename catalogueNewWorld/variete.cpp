#include "variete.h"

Variete::Variete(QString nom, QString description, QString image, QString nomProduit, int qte, float prix, QString nomProducteur, QString label)
{
    this->nom = nom;
    this->description = description;
    this->image = image;
    this->nomProduit = nomProduit;
    this->qte = qte;
    this->prix = prix;
    this->nomProducteur = nomProducteur;
    this->label = label;
    temp = HtmlTemplate("variete.html");
    temp.setValue("nom", nom);
    temp.setValue("description", description);
    temp.setValue("image", Passerelle::cheminImages+image);
    temp.setValue("produit",nomProduit);
    temp.setValue("producteur", nomProducteur);
    temp.setValue("prix", QString::number(prix));
}

QString Variete::toString()
{
    return this->temp.getChaine();
}


