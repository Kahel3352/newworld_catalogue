#ifndef TEMPLATE_H
#define TEMPLATE_H
#include <string>
#include <QString>
#include <QFile>
#include <QDebug>
using namespace std;

class HtmlTemplate
{
public:
    HtmlTemplate();
    HtmlTemplate(QString nom);
    void setValue(string key, QString value);
    void setStyle(QString nom);
    QString getChaine();
    static map<QString, QString> templates;

private:
    QString chaine;
    QString loadFile(QString nom);

};

#endif // TEMPLATE_H
