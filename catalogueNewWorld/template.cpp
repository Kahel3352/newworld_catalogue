#include "template.h"

map<QString, QString>HtmlTemplate::templates = map<QString, QString>();

HtmlTemplate::HtmlTemplate()
{

}

HtmlTemplate::HtmlTemplate(QString nom)
{
    qDebug()<<"HtmlTemplate::HtmlTemplate(QString nom)";
    if(HtmlTemplate::templates.count(nom)==0)
        HtmlTemplate::templates.insert(pair<QString, QString>(nom, this->loadFile("Templates/"+nom)));
    this->chaine = HtmlTemplate::templates[nom];
    //qDebug()<<this->chaine;
}

void HtmlTemplate::setValue(string key, QString value)
{
    this->chaine.replace(QString::fromStdString("$"+key), value);
}

void HtmlTemplate::setStyle(QString nom)
{
    this->setValue("style", this->loadFile("Style/"+nom));
}

QString HtmlTemplate::getChaine()
{
    return this->chaine;
}

QString HtmlTemplate::loadFile(QString nom)
{
    qDebug()<<"QString Template::loadFile(string nom)";

    QString fileChaine;

    //on essai d'ouvrir le fichier
    QFile file("../Ressources/"+nom);
    if(!file.open(QIODevice::ReadOnly)) {
        qDebug()<<"Impossible d'ouvrir ../Ressources/"+nom+": "+file.errorString();
    }
    QTextStream in(&file);

    //on met le fichier dans la chaine
    while(!in.atEnd()) {
        QString line = in.readLine();
        fileChaine+=line;
    }
    return fileChaine;
}
