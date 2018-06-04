#include "pdf.h"

Pdf::Pdf(QString nomDocument)
{
    qDebug() << "Pdf::Pdf(QString nomDocument)";
    this->pdfWriter = new QPdfWriter(nomDocument+".pdf");
    this->temp = HtmlTemplate("pdf.html");
    this->temp.setStyle("style.css");
    qDebug() << "fin Pdf::Pdf(QString nomDocument)";
}

Pdf::~Pdf()
{
    qDebug()<<"Pdf::~Pdf()";
    delete this->pdfWriter;
}

QString Pdf::ecrireTexte()
{
    qDebug() << "void Pdf::ecrireTexte()";
    Consommateur consommateur = Passerelle::chargerConsommateur();
    this->temp.setValue("nom", QString::fromStdString(consommateur.getNom()));
    this->temp.setValue("prenom", QString::fromStdString(consommateur.getPrenom()));
    this->temp.setValue("mail", QString::fromStdString(consommateur.getMail()));
    qDebug()<<"test: "+this->temp.getChaine();
    vector<Rayon> rayons = Passerelle::chargerRayons();
    QString chaineRayons = "";
    for(uint i = 0; i < rayons.size(); i++)
    {
        chaineRayons += rayons[i].toString();
    }
    this->temp.setValue("rayons", chaineRayons);
    return this->temp.getChaine();
}

string Pdf::chargerImage(string image)
{
    //return "<div align=\"center\"><img src=\"img/"+image+"\" height=150 width=250></div>";
}

void Pdf::imprimer()
{
    qDebug() << "void Pdf::imprimer()";
    QString test = "<!DOCTYPE html> <html> <head> <title>Catalogue NewWorld Maquette</title> <meta charset=\"utf-8\"> <style type=\"text/css\">@font-face {font-family: 'wanabees'; src: url('./Font/Wanabees/wannabees_personal_use-webfont.woff2') format('woff2'), url('./Font/Wanabees/wannabees_personal_use-webfont.woff') format('woff'); font-weight: normal; font-style: normal; } @font-face {font-family: 'moon_flower'; src: url('./Font/Moon_Flower/moon_flower-webfont.woff2') format('woff2'), url('./Font/Moon_Flower/moon_flower-webfont.woff') format('woff'); font-weight: normal; font-style: normal; } @font-face {font-family: 'moon_flower_bold'; src: url('./Font/Moon_Flower/moon_flower_bold-webfont.woff2') format('woff2'), url('./Font/Moon_Flower/moon_flower_bold-webfont.woff') format('woff'); font-weight: normal; font-style: normal; } @font-face {font-family:'TheLightFont'; src: url('./Font/The_Light_Font/TheLightFont.eot'); src: url('./Font/The_Light_Font/TheLightFont.eot?#iefix') format('embedded-opentype'), url('./Font/The_Light_Font/TheLightFont.woff2') format('woff2'), url('./Font/The_Light_Font/TheLightFont.woff') format('woff'), url('./Font/The_Light_Font/TheLightFont.svg#TheLightFont') format('svg'); font-weight: 400; font-style: normal; font-stretch: normal; unicode-range: U+0020-00FA; } h1 {font-family: wanabees; font-weight: lighter; font-size: 500%; text-align: center; color: #2D4747; text-shadow: -2px 0 #cc9966, 0 2px #cc9966, 2px 0 #cc9966, 0 -2px #cc9966; } .moonflowerB {font-family: moon_flower_bold; font-size: 200%; line-height: 10%; } td{border: 1px solid #cc9966; text-align: center; width: 500px; } .tableBorderColl{border-collapse: collapse; margin-left: auto; margin-right: auto; width:  1800px; } .tableBorderNone{border-collapse: collapse; } img{margin: 10px 20px 10px 20px; } .rayon{font-family: moon_flower_bold; font-size: 300%; text-align: center; } .produit{font-family: TheLightFont; font-size: 250%; color: #2D4747; } .variete{font-family: TheLightFont; font-size: 190%; color: #cc9966; } .texteProduit{font-family: TheLightFont; font-size: 145%; color: #2D4747; }</style> </head> <body> <h1>Catalogue NewWorld Maquette</h1> <div class=\"moonflowerB\"> <p>Consommateur</p> <p>Lebeau Mélanie</p> <p>melanie33130@live.fr</p> </div> <div> <br> <p class=\"rayon\">Fruits et Légumes</p> <table class=\"tableBorderColl\"> <tr> <td> <p class=\"produit\">Tomate</p> <p class=\"variete\">Bleue Osu</p> <div> <img src=\"../../ImgRessources/tomate_bleueosu.png\"> </div> <div class=\"texteProduit\"> <p>Variété rare de tomate bleue, au gout fade qui necessite un bon assaisonnement</p> <p>Produit par Théo Jouffreau</p> <p>au prix de 5.80 /kg</p> </div> </td> <td> <p class=\"produit\">Tomate</p> <p class=\"variete\">Bleue Osu</p> <div> <img src=\"../../ImgRessources/tomate_bleueosu.png\"> </div> <div class=\"texteProduit\"> <p>Variété rare de tomate bleue, au gout fade qui necessite un bon assaisonnement</p> <p>Produit par Maxime Iori</p> <p>au prix de 10 /kg</p> </div> </td> <td> <p class=\"produit\">Carotte</p> <p class=\"variete\">Blanche des Vosges</p> <div> <img src=\"../../ImgRessources/carotte_blanchedesvosges.png\"> </div> <div class=\"texteProduit\"> <p>Variété ancienne de carotte, elle est gouteuse si elle est récoltée jeune, utilisé  en fourragère pour des récoltes de racines plus agées.</p> <p>Produit par Maxime Iori</p> <p>au prix de 6/kg</p> </div> </td> </tr> <tr> <td> <p class=\"produit\">Poire</p> <p class=\"variete\">Comice</p> <img src=\"../../ImgRessources/poire_comice.png\"> <div class=\"texteProduit\"> <p>Variété fragile de poire, a la chaire blanche, juteuse et fondante, extrêmement parfumée et sucrée.</p> <p>Produit par Théo Jouffreau</p> <p>au prix de 7.80/kg</p> </div> </td> <td> <p class=\"produit\">Un autre produit</p> </td> <td> <p class=\"produit\">Un autre produit</p> </td> </tr> </table> <br> <p class=\"rayon\">Viandes<p> <table class=\"tableBorderColl\"> <tr> <td><p class=\"produit\">Un autre produit</p></td> <td><p class=\"produit\">Un autre produit</p></td> <td><p class=\"produit\">Un autre produit</p></td> </tr> </table> </div> </body> </html>";
    QTextDocument textDocument;
    QString codeHtml = this->ecrireTexte();
    textDocument.setHtml(codeHtml);
    qDebug()<<"Html généré: ";
    qDebug()<<codeHtml;
    textDocument.print(this->pdfWriter);

}
