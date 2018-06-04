#include "rayon.h"


Rayon::Rayon()
{

}

Rayon::Rayon(int id, QString nom)
{
    qDebug() << "Rayon::Rayon(int id, string nom)";
    this->id = id;
    this->nom = nom;
    this->chargerVarietes();
    this->temp = HtmlTemplate("rayon.html");
    this->temp.setValue("nom",nom);

}

QString Rayon::toString()
{
    qDebug()<<"QString Rayon::toString()";
    vector<Variete> varietes = Passerelle::chargerVariete(this->id);
    QString chaineVarietes = "";
    for(uint i = 0; i < varietes.size(); i++)
    {
        //si c'est un début de ligne
        if(i%3==0)
        {
            //si c'est pas la première ligne
            if(i!=0)
                //je referme la <tr> précedente
                chaineVarietes+="</tr>";
            chaineVarietes+="<tr>";
        }

        chaineVarietes+=varietes[i].toString();
    }
    temp.setValue("varietes", chaineVarietes);
    return this->temp.getChaine();
}

vector<Variete> *Rayon::getLesVarietes()
{
    return &this->lesVarietes;
}

void Rayon::chargerVarietes()
{
    this->lesVarietes = Passerelle::chargerVariete(this->id);
}
