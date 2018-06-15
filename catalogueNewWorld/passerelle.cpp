#include "passerelle.h"

QSqlDatabase Passerelle::db = QSqlDatabase::addDatabase("QMYSQL3");
int Passerelle::userId = 0;
QString Passerelle::cheminImages = "../ImgRessources/";

void Passerelle::setDatabase()
{
    qDebug() << "void Passerelle::setDatabase()";
    db.setHostName("localhost");
    db.setDatabaseName("nw");
    db.setUserName("root");
    db.setPassword("ini01");
}

vector<Rayon> Passerelle::chargerRayons()
{
    qDebug() << "vector<Rayon> Passerelle::chargerRayons()";
    vector<Rayon> vectRayon;
    if(!db.open())
        qDebug()<<db.lastError().text();
    else
    {
        QString txtReq = "SELECT DISTINCT Rayon.rayonId, Rayon.rayonLibelle FROM Rayon INNER JOIN Produit ON Rayon.rayonId = Produit.rayonId INNER JOIN Variete ON Variete.produitId = Produit.produitId INNER JOIN Lot ON Lot.varieteId = Variete.varieteId INNER JOIN Parcelle ON Parcelle.parcelleId = Lot.parcelleId INNER JOIN Producteur ON Producteur.producteurId = Parcelle.producteurId INNER JOIN Utilisateur ON Utilisateur.userId = Producteur.userId INNER JOIN RelaiPossible ON RelaiPossible.relaiId = RelaiPossible.userId WHERE RelaiPossible.relaiId IN (SELECT RelaiPossible.relaiId FROM RelaiPossible WHERE RelaiPossible.userId = ?) AND Variete.varieteValid = 1;";
        QSqlQuery query;
        query.prepare(txtReq);
        query.addBindValue(userId);

        if(query.exec())
        {
            while(query.next())
            {
                vectRayon.push_back(Rayon(query.value("rayonId").toInt(), query.value("rayonLibelle").toString()));
            }
        }
        else
            qDebug()<<query.lastError().text();


    }

    db.close();
    return vectRayon;
}

vector<Variete> Passerelle::chargerVariete(int idRayon)
{
    qDebug() << "vector<Variete> Passerelle::chargerVariete(int idRayon)";
    vector<Variete> vectVariete;
    if(!db.open())
        qDebug()<<db.lastError().text();
    else
    {
        QString txtReq = "SELECT DISTINCT Produit.produitLibelle, Variete.varieteNom, Variete.varieteDescr, Variete.varieteImg, Utilisateur.userNom, Lot.lotQte, Lot.lotPrix, Unite.uniteLibelle FROM Produit INNER JOIN Variete ON Variete.produitId = Produit.produitId INNER JOIN Lot ON Lot.varieteId = Variete.varieteId INNER JOIN Parcelle ON Parcelle.parcelleId = Lot.parcelleId INNER JOIN Producteur ON Producteur.producteurId = Parcelle.producteurId INNER JOIN Utilisateur ON Utilisateur.userId = Producteur.userId INNER JOIN RelaiPossible ON RelaiPossible.relaiId = RelaiPossible.userId INNER JOIN Unite ON Unite.uniteId = Produit.uniteId WHERE RelaiPossible.relaiId IN (SELECT RelaiPossible.relaiId FROM RelaiPossible WHERE RelaiPossible.userId = ?) AND Variete.varieteValid = 1 AND Produit.rayonId = ? AND Lot.lotDLC > CURDATE();";
        QSqlQuery query;
        query.prepare(txtReq);
        query.addBindValue(userId);
        query.addBindValue(idRayon);

        if(query.exec())
        {
            while(query.next())
            {
                vectVariete.push_back(Variete(query.value("varieteNom").toString(), query.value("varieteDescr").toString(), query.value("varieteImg").toString(), query.value("produitLibelle").toString(), query.value("lotQte").toFloat(), query.value("lotPrix").toFloat(), query.value("userNom").toString(),QString("")));
            }
        }
        else
            cout<<query.lastError().text().toStdString()<<endl;


    }

    db.close();
    return vectVariete;
}

Consommateur Passerelle::chargerConsommateur()
{
    qDebug() << "Consommateur Passerelle::chargerConsommateur(int id)";
    if(!db.open())
        cout<<db.lastError().text().toStdString()<<endl;
    else
    {
        QString txtReq = "SELECT DISTINCT userNom, userPrenom, userMail FROM Utilisateur where userId = ?;";
        QSqlQuery query;
        query.prepare(txtReq);
        query.addBindValue(userId);
        if(query.exec())
        {
            query.first();
            return Consommateur(query.value("userNom").toString().toStdString(), query.value("userPrenom").toString().toStdString(),query.value("userMail").toString().toStdString());
        }
        else
            qDebug()<<query.lastError().text();
    }

    db.close();
    return Consommateur();
}
int Passerelle::getUserId()
{
    return userId;
}

void Passerelle::setUserId(int value)
{
    userId = value;
}

