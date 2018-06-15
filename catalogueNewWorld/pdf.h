#ifndef PDF_H
#define PDF_H

#include <string>
#include <iostream>
#include <QString>
#include <QPdfWriter>
#include <QTextDocument>
#include "passerelle.h"
#include "template.h"

using namespace std;

/**
 * @brief Représente un fichier au format PDF
 */
class Pdf
{
public:
    /**
     * @brief Constructeur de Pdf
     * @param Nom du document
     */
    Pdf(QString nomDocument);

    ~Pdf();

    /**
     * @brief Génère le code HTML qui corréspond au catalogue
     * @return Chaine de caractères contenant le code HTML
     */
    QString ecrireTexte();

    /**
     * @brief Ecris le fichier PDf
     */
    void imprimer();

private:
    /**
     * @brief Nom du document
     */
    QPdfWriter* pdfWriter;
    HtmlTemplate temp;
};

#endif // PDF_H
