#include "variete.h"

/*string Variete::toString()
{
    string chaine = "";
    chaine+="<p class=\""+this->nomProduit+"\">Tomate</p>";
    chaine+="<p class=\""+variete+"\">Bleue Osu</p>";
    chaine+="<div>";
    chaine+="<img src=\"../../ImgRessources/"+this->image+"\">";
    chaine+="</div>";
    chaine+="<div class=\""+texteProduit+"\">";
    chaine+="<p>"+this->description"</p>";
    chaine+="<p>Produit par "+nomProducteur+"</p>";
    chaine+="<p>au prix de "+this->prix+"</p>";
    chaine+="</div>";


    chaine+=this->nom;

    return chaine;
}*/

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
    temp.setValue("image", "../ImgRessources/"+image);
    temp.setValue("produit",nomProduit);
    temp.setValue("producteur", nomProducteur);
}

QString Variete::toString()
{
    return this->temp.getChaine();
}


