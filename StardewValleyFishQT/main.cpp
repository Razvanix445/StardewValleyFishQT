/*
Aplicatie gestiune pesti Stardew Valley:
Un obiect "Pește" va avea:
- nume
- anotimp
- vreme
- locatie
- timp
- dificultate
1. Adaugare pește
2. Modificare pește
3. Ștergere pește
4. Căutare pește
5. Filtrare pești după: anotimp (+ sortare dupa locatie)
*/

#include <iostream>
#include "Peste.h"
#include "repo.h"
#include "service.h"
#include "teste.h"
#include "GUI.h"
#include <QtWidgets/QApplication>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ruleazaToateTestele();

    QMainWindow fereastraPrincipala;
    fereastraPrincipala.setWindowTitle("Aplicația mea");
    fereastraPrincipala.showMaximized();
    //fereastraPrincipala.setMinimumSize(1550, 850);

    QPixmap backgroundImage("Screenshot 2023-10-05 132000.png");
    //QPixmap backgroundImage("StardewFishingBackground.jpg");
    //backgroundImage = backgroundImage.scaled(fereastraPrincipala.size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPalette palette;
    palette.setBrush(QPalette::Window, backgroundImage);
    fereastraPrincipala.setPalette(palette);

    QPushButton* butonPornire = new QPushButton("Start", &fereastraPrincipala);
    QLabel* textAplicatiaMea = new QLabel("", &fereastraPrincipala);
    textAplicatiaMea->setAlignment(Qt::AlignCenter);

    //Adaugam widgets la widgetPrincipal
    QVBoxLayout* layoutPrincipal = new QVBoxLayout(&fereastraPrincipala);
    layoutPrincipal->addWidget(textAplicatiaMea, 0, Qt::AlignCenter);
    layoutPrincipal->addWidget(butonPornire, 0, Qt::AlignCenter);

    QWidget* widgetPrincipal = new QWidget(&fereastraPrincipala);
    widgetPrincipal->setLayout(layoutPrincipal);
    fereastraPrincipala.setCentralWidget(widgetPrincipal);

    //Afisam fereastra        pestiFarm.txt
    Repo repository;
    RepoFile repositoryFile{ "pesti.txt" };
    Validator validator;
    Service service{ repositoryFile, validator };
    PestiGUI* pesti_gui = new PestiGUI{ service };

    QObject::connect(butonPornire, &QPushButton::clicked, [&]() {
        pesti_gui->showMaximized();
        pesti_gui->setAttribute(Qt::WA_DeleteOnClose);
        pesti_gui->show();

        fereastraPrincipala.hide();
        });

    QFont font("Comic Sans MS");
    app.setFont(font);

    fereastraPrincipala.show();

    return app.exec();
}