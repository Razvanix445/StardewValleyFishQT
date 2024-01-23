#pragma once
#include "service.h"
#include <QApplication>
#include <QHBoxLayout>
#include <QTableWidget>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>
#include <QHeaderView>
#include <QMessageBox>
#include <QCheckBox>
#include <QTextEdit>
#include <QDebug>
#include <QComboBox>
#include <QSplitter>
#include <QScrollArea>
#include <QLabel>
#include <vector>
#include <string>

class PestiGUI : public QWidget {

public:

	PestiGUI(Service& service) : service{ service } {
		initGUI();
		loadData();
		initConnect();
	}

private:

	Service& service;
	vector<Peste> pesti;

    QScrollArea* scrollArea = new QScrollArea();
    QTableWidget* tabelPesti = new QTableWidget();
    QTableWidget* tabelPestiMic = new QTableWidget();

    QLineEdit* numeEdit = new QLineEdit;
    QLineEdit* anotimpEdit = new QLineEdit;
    QLineEdit* vremeEdit = new QLineEdit;
    QLineEdit* locatieEdit = new QLineEdit;
    QLineEdit* oraInceputEdit = new QLineEdit;
    QLineEdit* oraSfarsitEdit = new QLineEdit;
    QLineEdit* dificultateEdit = new QLineEdit;
    QLineEdit* prinsEdit = new QLineEdit;

    QLineEdit* anotimpFiltrareEdit = new QLineEdit;
    QLineEdit* locatieFiltrareEdit = new QLineEdit;
    QLineEdit* prinsFiltrareEdit = new QLineEdit;

    QLineEdit* lineEditReperSortare = new QLineEdit;
    QLineEdit* lineEditOrdineSortare = new QLineEdit;

    //QLineEdit* numeFisierHTML = new QLineEdit;

    QPushButton* butonStergereNume = new QPushButton{ "&Șterge" };
    QPushButton* butonStergereAnotimp = new QPushButton{ "&Șterge" };
    QPushButton* butonStergereVreme = new QPushButton{ "&Șterge" };
    QPushButton* butonStergereLocatie = new QPushButton{ "&Șterge" };
    QPushButton* butonStergereOraInceput = new QPushButton{ "&Șterge" };
    QPushButton* butonStergereOraSfarsit = new QPushButton{ "&Șterge" };
    QPushButton* butonStergereDificultate = new QPushButton{ "&Șterge" };
    QPushButton* butonStergerePrins = new QPushButton{ "&Șterge" };
    QPushButton* butonStergere = new QPushButton{ "&Șterge toate câmpurile" };

    QPushButton* butonExit = new QPushButton{ "&Exit" };
    QPushButton* butonAdauga = new QPushButton{ "&Adaugă" };
    QPushButton* butonSterge = new QPushButton{ "&Șterge" };
    QPushButton* butonModifica = new QPushButton{ "&Modifică" };
    QPushButton* butonCauta = new QPushButton{ "&Caută" };
    QPushButton* butonFiltreaza = new QPushButton{ "&Filtrează" };
    QPushButton* butonSorteaza = new QPushButton{ "&Sortează" };

    //QPushButton* butonExportInHTML = new QPushButton{ "&Exportă coșul în HTML" };

    QLabel* numarPestiLabel = new QLabel("Număr de filme: ");
    QString numarPesti = QString::number(service.getAll().size());
    QLabel* numarPestiLabelMic = new QLabel("Număr de filme: ");
    QString numarPestiMic = QString::number(0);

	void initGUI() {
        QHBoxLayout* layoutPrincipal = new QHBoxLayout{};
        auto layoutDreapta = new QVBoxLayout;
        auto layoutStanga = new QVBoxLayout;
        auto layoutDreaptaSus = new QVBoxLayout;
        auto layoutDreaptaCentru = new QVBoxLayout;
        auto layoutDreaptaCentruJos = new QVBoxLayout;
        auto layoutDreaptaJos = new QVBoxLayout;

        setLayout(layoutPrincipal);

        //Layout Stanga
        auto layoutLista = new QHBoxLayout{};

        tabelPesti->setColumnCount(8);
        tabelPesti->setHorizontalHeaderLabels(QStringList() << "Nume" << "Anotimp" << "Vreme" << "Locatie" << "Ora Inceput" << "Ora Sfarsit" << "Dificultate" << "Prins/Neprins");

        //Layout Dreapta Centru
        QFont fontTextMic = tabelPestiMic->font();
        fontTextMic.setPointSize(12);
        numeEdit->setFont(fontTextMic), anotimpEdit->setFont(fontTextMic), vremeEdit->setFont(fontTextMic), locatieEdit->setFont(fontTextMic),
            oraInceputEdit->setFont(fontTextMic), oraSfarsitEdit->setFont(fontTextMic), dificultateEdit->setFont(fontTextMic), prinsEdit->setFont(fontTextMic);

        tabelPestiMic->setColumnCount(8);
        tabelPestiMic->setHorizontalHeaderLabels(QStringList() << "Nume" << "Anotimp" << "Vreme" << "Locatie" << "Ora Inceput" << "Ora Sfarsit" << "Dificultate" << "Prins/Neprins");

        numarPestiLabelMic->setText("Număr de pești: " + numarPestiMic);
        layoutDreaptaCentru->addWidget(tabelPestiMic, 1);
        layoutDreaptaCentru->addWidget(numarPestiLabelMic);

        //Layout Dreapta Sus
        auto formLayout = new QFormLayout;
        formLayout->addRow("Denumire", numeEdit);
        formLayout->addRow("Anotimp", anotimpEdit);
        formLayout->addRow("Vreme", vremeEdit);
        formLayout->addRow("Locatie", locatieEdit);
        formLayout->addRow("Ora Inceput", oraInceputEdit);
        formLayout->addRow("Ora Sfarsit", oraSfarsitEdit);
        formLayout->addRow("Dificultate", dificultateEdit);
        formLayout->addRow("Prins/Neprins", prinsEdit);

        QFont fontText = tabelPesti->font();
        fontText.setPointSize(12);
        numeEdit->setFont(fontText), anotimpEdit->setFont(fontText), vremeEdit->setFont(fontText), locatieEdit->setFont(fontText), 
            oraInceputEdit->setFont(fontText), oraSfarsitEdit->setFont(fontText), dificultateEdit->setFont(fontText), prinsEdit->setFont(fontText);

        numarPestiLabel->setText("Număr de pești: " + numarPesti);
        layoutStanga->addWidget(tabelPesti, 1);
        layoutStanga->addWidget(numarPestiLabel);

        auto butoaneStergereLayout = new QVBoxLayout;
        butoaneStergereLayout->addWidget(butonStergereNume);
        butoaneStergereLayout->addWidget(butonStergereAnotimp);
        butoaneStergereLayout->addWidget(butonStergereVreme);
        butoaneStergereLayout->addWidget(butonStergereLocatie);
        butoaneStergereLayout->addWidget(butonStergereOraInceput);
        butoaneStergereLayout->addWidget(butonStergereOraSfarsit);
        butoaneStergereLayout->addWidget(butonStergereDificultate);
        butoaneStergereLayout->addWidget(butonStergerePrins);
        butoaneStergereLayout->addWidget(butonStergere);

        QFont fontButoaneStergere = tabelPesti->font();
        fontButoaneStergere.setPointSize(10);
        butonStergereNume->setFont(fontButoaneStergere), butonStergereAnotimp->setFont(fontButoaneStergere), butonStergereVreme->setFont(fontButoaneStergere), butonStergereLocatie->setFont(fontButoaneStergere), 
            butonStergereOraInceput->setFont(fontButoaneStergere), butonStergereOraSfarsit->setFont(fontButoaneStergere), butonStergereDificultate->setFont(fontButoaneStergere), butonStergerePrins->setFont(fontButoaneStergere);

        //Layout Dreapta Jos
        auto layoutButoaneAdaugareStergereModificareCautare = new QHBoxLayout{};
        auto layoutButoaneFiltrareSortare = new QHBoxLayout{};
        QFormLayout* formLayoutFiltrare = new QFormLayout;
        QFormLayout* formLayoutSortare = new QFormLayout;
        auto layoutButoaneUndoExit = new QHBoxLayout{};
        auto formLayoutCuButoane = new QHBoxLayout{};

        layoutButoaneAdaugareStergereModificareCautare->addWidget(butonAdauga);
        layoutButoaneAdaugareStergereModificareCautare->addWidget(butonSterge);
        layoutButoaneAdaugareStergereModificareCautare->addWidget(butonModifica);
        layoutButoaneAdaugareStergereModificareCautare->addWidget(butonCauta);
        formLayoutFiltrare->addWidget(butonFiltreaza);
        formLayoutFiltrare->addRow(anotimpFiltrareEdit);
        formLayoutFiltrare->addRow(locatieFiltrareEdit);
        formLayoutFiltrare->addRow(prinsFiltrareEdit);
        formLayoutSortare->addWidget(butonSorteaza);
        formLayoutSortare->addRow(lineEditOrdineSortare);
        formLayoutSortare->addRow(lineEditReperSortare);
        layoutButoaneFiltrareSortare->addLayout(formLayoutFiltrare);
        layoutButoaneFiltrareSortare->addLayout(formLayoutSortare);
        layoutButoaneUndoExit->addWidget(butonExit);

        anotimpFiltrareEdit->setPlaceholderText("Anotimp...");
        locatieFiltrareEdit->setPlaceholderText("Locatie...");
        prinsFiltrareEdit->setPlaceholderText("X/-...");
        lineEditOrdineSortare->setPlaceholderText("Ordine sortare...");
        lineEditReperSortare->setPlaceholderText("Reper sortare...");

        QFont fontButoane = tabelPesti->font();
        fontButoane.setPointSize(10);
        butonAdauga->setFont(fontButoane), butonSterge->setFont(fontButoane), butonModifica->setFont(fontButoane), butonCauta->setFont(fontButoane);
        butonFiltreaza->setFont(fontButoane), butonSorteaza->setFont(fontButoane), butonExit->setFont(fontButoane);

        //Adaugam splitter (despartitor) intre layoutStanga si layoutDreapta
        QSplitter* splitter = new QSplitter(Qt::Horizontal, this);
        splitter->setOpaqueResize(false);
        layoutPrincipal->addWidget(splitter);
        QWidget* widgetStanga = new QWidget();
        widgetStanga->setLayout(layoutStanga);
        QWidget* widgetDreapta = new QWidget();
        widgetDreapta->setLayout(layoutDreapta);
        splitter->addWidget(widgetStanga);
        splitter->addWidget(widgetDreapta);
        splitter->setStretchFactor(0, 1);

        //Organizare Layouts
        formLayoutCuButoane->addLayout(formLayout);
        formLayoutCuButoane->addLayout(butoaneStergereLayout);
        layoutDreaptaSus->addLayout(formLayoutCuButoane);
        layoutDreaptaSus->addStretch();

        layoutDreaptaCentru->addWidget(tabelPestiMic);

        layoutDreaptaJos->addStretch();
        layoutDreaptaJos->addLayout(layoutButoaneAdaugareStergereModificareCautare);
        layoutDreaptaJos->addLayout(layoutButoaneFiltrareSortare);
        layoutDreaptaJos->addLayout(layoutButoaneUndoExit);

        layoutLista->addLayout(layoutStanga);
        layoutLista->addLayout(layoutDreapta);

        layoutDreapta->addLayout(layoutDreaptaSus);
        layoutDreapta->addLayout(layoutDreaptaCentru);
        layoutDreapta->addLayout(layoutDreaptaJos);

        layoutPrincipal->addLayout(layoutLista);
	}

    void updateTabel(vector<Peste>& pesti) {
        tabelPesti->clearContents();
        tabelPesti->setRowCount(0);

        for (const auto& peste : pesti) {
            int row = tabelPesti->rowCount();
            tabelPesti->insertRow(row);

            QTableWidgetItem* numeItem = new QTableWidgetItem(QString::fromStdString(peste.getNumePeste()));
            QTableWidgetItem* anotimpItem = new QTableWidgetItem(QString::fromStdString(peste.getAnotimp()));
            QTableWidgetItem* vremeItem = new QTableWidgetItem(QString::fromStdString(peste.getVreme()));
            QTableWidgetItem* locatieItem = new QTableWidgetItem(QString::fromStdString(peste.getLocatie()));
            QTableWidgetItem* oraInceputItem = new QTableWidgetItem(QString::number(peste.getOraInceput()));
            QTableWidgetItem* oraSfarsitItem = new QTableWidgetItem(QString::number(peste.getOraSfarsit()));
            QTableWidgetItem* dificultateItem = new QTableWidgetItem(QString::number(peste.getDificultate()));
            QTableWidgetItem* prinsItem = new QTableWidgetItem(QString::fromStdString(peste.getPrins()));

            tabelPesti->setItem(row, 0, numeItem);
            tabelPesti->setItem(row, 1, anotimpItem);
            tabelPesti->setItem(row, 2, vremeItem);
            tabelPesti->setItem(row, 3, locatieItem);
            tabelPesti->setItem(row, 4, oraInceputItem);
            tabelPesti->setItem(row, 5, oraSfarsitItem);
            tabelPesti->setItem(row, 6, dificultateItem);
            tabelPesti->setItem(row, 7, prinsItem);
        }
        for (int column = 0; column < tabelPesti->columnCount() - 1; ++column) {
            tabelPesti->horizontalHeader()->setSectionResizeMode(column, QHeaderView::ResizeToContents);
        }
        tabelPesti->horizontalHeader()->setSectionResizeMode(tabelPesti->columnCount() - 1, QHeaderView::Stretch);

        int numarPesti = pesti.size();
        numarPestiLabel->setText("Număr de pești: " + QString::number(numarPesti));
    }

    void updateTabelMic(vector<Peste>& pesti) {
        tabelPestiMic->clearContents();
        tabelPestiMic->setRowCount(0);

        for (const auto& peste : pesti) {
            int row = tabelPestiMic->rowCount();
            tabelPestiMic->insertRow(row);

            QTableWidgetItem* numeItem = new QTableWidgetItem(QString::fromStdString(peste.getNumePeste()));
            QTableWidgetItem* anotimpItem = new QTableWidgetItem(QString::fromStdString(peste.getAnotimp()));
            QTableWidgetItem* vremeItem = new QTableWidgetItem(QString::fromStdString(peste.getVreme()));
            QTableWidgetItem* locatieItem = new QTableWidgetItem(QString::fromStdString(peste.getLocatie()));
            QTableWidgetItem* oraInceputItem = new QTableWidgetItem(QString::number(peste.getOraInceput()));
            QTableWidgetItem* oraSfarsitItem = new QTableWidgetItem(QString::number(peste.getOraSfarsit()));
            QTableWidgetItem* dificultateItem = new QTableWidgetItem(QString::number(peste.getDificultate()));
            QTableWidgetItem* prinsItem = new QTableWidgetItem(QString::fromStdString(peste.getPrins()));

            tabelPestiMic->setItem(row, 0, numeItem);
            tabelPestiMic->setItem(row, 1, anotimpItem);
            tabelPestiMic->setItem(row, 2, vremeItem);
            tabelPestiMic->setItem(row, 3, locatieItem);
            tabelPestiMic->setItem(row, 4, oraInceputItem);
            tabelPestiMic->setItem(row, 5, oraSfarsitItem);
            tabelPestiMic->setItem(row, 6, dificultateItem);
            tabelPestiMic->setItem(row, 7, prinsItem);
        }
        for (int column = 0; column < tabelPesti->columnCount() - 1; ++column) {
            tabelPestiMic->horizontalHeader()->setSectionResizeMode(column, QHeaderView::ResizeToContents);
        }
        tabelPestiMic->horizontalHeader()->setSectionResizeMode(tabelPestiMic->columnCount() - 1, QHeaderView::Stretch);

        int numarPestiMic = pesti.size();
        numarPestiLabelMic->setText("Număr de pești: " + QString::number(numarPestiMic));
    }

	void loadData() {
        tabelPesti->clearContents();
        tabelPesti->setRowCount(0);

        auto pesti = service.getAll();
        for (const auto& peste : pesti) {
            int row = tabelPesti->rowCount();
            tabelPesti->insertRow(row);

            QTableWidgetItem* numeItem = new QTableWidgetItem(QString::fromStdString(peste.getNumePeste()));
            QTableWidgetItem* anotimpItem = new QTableWidgetItem(QString::fromStdString(peste.getAnotimp()));
            QTableWidgetItem* vremeItem = new QTableWidgetItem(QString::fromStdString(peste.getVreme()));
            QTableWidgetItem* locatieItem = new QTableWidgetItem(QString::fromStdString(peste.getLocatie()));
            QTableWidgetItem* oraInceputItem = new QTableWidgetItem(QString::number(peste.getOraInceput()));
            QTableWidgetItem* oraSfarsitItem = new QTableWidgetItem(QString::number(peste.getOraSfarsit()));
            QTableWidgetItem* dificultateItem = new QTableWidgetItem(QString::number(peste.getDificultate()));
            QTableWidgetItem* prinsItem = new QTableWidgetItem(QString::fromStdString(peste.getPrins()));

            tabelPesti->setItem(row, 0, numeItem);
            tabelPesti->setItem(row, 1, anotimpItem);
            tabelPesti->setItem(row, 2, vremeItem);
            tabelPesti->setItem(row, 3, locatieItem);
            tabelPesti->setItem(row, 4, oraInceputItem);
            tabelPesti->setItem(row, 5, oraSfarsitItem);
            tabelPesti->setItem(row, 6, dificultateItem);
            tabelPesti->setItem(row, 7, prinsItem);
        }
        for (int column = 0; column < tabelPesti->columnCount() - 1; ++column) {
            tabelPesti->horizontalHeader()->setSectionResizeMode(column, QHeaderView::ResizeToContents);
        }
        tabelPesti->horizontalHeader()->setSectionResizeMode(tabelPesti->columnCount() - 1, QHeaderView::Stretch);

        int numarPesti = service.getAll().size();
        numarPestiLabel->setText("Număr de pești: " + QString::number(numarPesti));
	}

    void initConnect() {
        QObject::connect(butonExit, &QPushButton::clicked, []() {
            qApp->quit();
            });

        QObject::connect(butonAdauga, &QPushButton::clicked, [&]() {
            auto nume = numeEdit->text().toStdString();
            auto anotimp = anotimpEdit->text().toStdString();
            auto vreme = vremeEdit->text().toStdString();
            auto locatie = locatieEdit->text().toStdString();
            auto oraInceput = oraInceputEdit->text().toInt();
            auto oraSfarsit = oraSfarsitEdit->text().toInt();
            auto dificultate = dificultateEdit->text().toInt();
            auto prins = prinsEdit->text().toStdString();

            if (nume.empty() || anotimp.empty() || vreme.empty() || locatie.empty() || !oraInceput || !oraSfarsit || !dificultate || prins.empty()) {
                QMessageBox::information(this, "Ceva nu a mers bine!", "Ceva nu a mers bine!");
                return;
            }

            try {
                service.adaugaPeste(nume, anotimp, vreme, locatie, oraInceput, oraSfarsit, dificultate, prins);
            }
            catch (ExceptieRepo& exceptie) {
                QMessageBox::warning(this, "Atenție!", QString::fromStdString(exceptie.getMesaj()));
            }
            catch (ExceptieValidare& exceptie) {
                QMessageBox::warning(this, "Atenție!", QString::fromStdString(exceptie.getMesaj()[0]));
            }

            loadData();
            });

        QObject::connect(butonSterge, &QPushButton::clicked, [&]() {
            auto nume = numeEdit->text().toStdString();

            if (nume.empty()) {
                QMessageBox::information(this, "Ceva nu a mers bine!", "Ceva nu a mers bine!");
                return;
            }

            try {
                service.stergePeste(nume);
            }
            catch (ExceptieRepo& exceptie) {
                QMessageBox::warning(this, "Atenție!", QString::fromStdString(exceptie.getMesaj()));
            }
            catch (ExceptieValidare& exceptie) {
                QMessageBox::warning(this, "Atenție!", QString::fromStdString(exceptie.getMesaj()[0]));
            }

            loadData();
            });

        QObject::connect(butonModifica, &QPushButton::clicked, [&]() {
            auto nume = numeEdit->text().toStdString();
            auto anotimp = anotimpEdit->text().toStdString();
            auto vreme = vremeEdit->text().toStdString();
            auto locatie = locatieEdit->text().toStdString();
            auto oraInceput = oraInceputEdit->text().toInt();
            auto oraSfarsit = oraSfarsitEdit->text().toInt();
            auto dificultate = dificultateEdit->text().toInt();
            auto prins = prinsEdit->text().toStdString();

            if (nume.empty() || anotimp.empty() || vreme.empty() || locatie.empty() || !oraInceput || !oraSfarsit || !dificultate || prins.empty()) {
                QMessageBox::information(this, "Ceva nu a mers bine!", "Ceva nu a mers bine!");
                return;
            }

            try {
                service.modificaPeste(nume, anotimp, vreme, locatie, oraInceput, oraSfarsit, dificultate, prins);
            }
            catch (ExceptieRepo& exceptie) {
                QMessageBox::warning(this, "Atenție!", QString::fromStdString(exceptie.getMesaj()));
            }
            catch (ExceptieValidare& exceptie) {
                QMessageBox::warning(this, "Atenție!", QString::fromStdString(exceptie.getMesaj()[0]));
            }

            loadData();
            });

        QObject::connect(butonCauta, &QPushButton::clicked, [&]() {
            if (numeEdit->text() != "") {
                try {
                    auto peste = service.cautaPeste(numeEdit->text().toStdString());

                    tabelPestiMic->clearContents();
                    tabelPestiMic->setRowCount(0);
                    int row = tabelPestiMic->rowCount();
                    tabelPestiMic->insertRow(row);
                    
                    QTableWidgetItem* numeItem = new QTableWidgetItem(QString::fromStdString(peste.getNumePeste()));
                    QTableWidgetItem* anotimpItem = new QTableWidgetItem(QString::fromStdString(peste.getAnotimp()));
                    QTableWidgetItem* vremeItem = new QTableWidgetItem(QString::fromStdString(peste.getVreme()));
                    QTableWidgetItem* locatieItem = new QTableWidgetItem(QString::fromStdString(peste.getLocatie()));
                    QTableWidgetItem* oraInceputItem = new QTableWidgetItem(QString::number(peste.getOraInceput()));
                    QTableWidgetItem* oraSfarsitItem = new QTableWidgetItem(QString::number(peste.getOraSfarsit()));
                    QTableWidgetItem* dificultateItem = new QTableWidgetItem(QString::number(peste.getDificultate()));
                    QTableWidgetItem* prinsItem = new QTableWidgetItem(QString::fromStdString(peste.getPrins()));

                    tabelPestiMic->setItem(row, 0, numeItem);
                    tabelPestiMic->setItem(row, 1, anotimpItem);
                    tabelPestiMic->setItem(row, 2, vremeItem);
                    tabelPestiMic->setItem(row, 3, locatieItem);
                    tabelPestiMic->setItem(row, 4, oraInceputItem);
                    tabelPestiMic->setItem(row, 5, oraSfarsitItem);
                    tabelPestiMic->setItem(row, 6, dificultateItem);
                    tabelPestiMic->setItem(row, 7, prinsItem);
                }
                catch (ExceptieRepo& exceptie) {
                    QMessageBox::warning(this, "Atenție!", QString::fromStdString(exceptie.getMesaj()));
                }
                catch (ExceptieValidare& exceptie) {
                    QMessageBox::warning(this, "Atenție!", QString::fromStdString(exceptie.getMesaj()[0]));
                }
            }
            });

        QObject::connect(butonFiltreaza, &QPushButton::clicked, [&]() {
            if (locatieFiltrareEdit->text() == "" && anotimpFiltrareEdit->text() == "" && prinsFiltrareEdit->text() != "") {
                vector<Peste> pesti = service.filtreazaDupaPrinsNeprins(prinsFiltrareEdit->text().toStdString(), service.getAll());
                updateTabelMic(pesti);
                updateTabel(pesti);
            }
            if (locatieFiltrareEdit->text() != "" && anotimpFiltrareEdit->text() != "") {
                vector<Peste> pesti = service.filtreazaDupaLocatieSiAnotimp(locatieFiltrareEdit->text().toStdString(), anotimpFiltrareEdit->text().toStdString());
                if (prinsFiltrareEdit->text().toStdString() != "") {
                    vector<Peste> pestiPrinsNeprins = service.filtreazaDupaPrinsNeprins(prinsFiltrareEdit->text().toStdString(), pesti);
                    updateTabelMic(pestiPrinsNeprins);
                    updateTabel(pestiPrinsNeprins);
                }
                else {
                    updateTabelMic(pesti);
                    updateTabel(pesti);
                }
            }
            if (locatieFiltrareEdit->text() == "" && anotimpFiltrareEdit->text() != "") {
                vector<Peste> pesti = service.filtreazaDupaAnotimp(anotimpFiltrareEdit->text().toStdString());
                if (prinsFiltrareEdit->text().toStdString() != "") {
                    vector<Peste> pestiPrinsNeprins = service.filtreazaDupaPrinsNeprins(prinsFiltrareEdit->text().toStdString(), pesti);
                    updateTabelMic(pestiPrinsNeprins);
                    updateTabel(pestiPrinsNeprins);
                }
                else {
                    updateTabelMic(pesti);
                    updateTabel(pesti);
                }
            }
            });

        QObject::connect(butonSorteaza, &QPushButton::clicked, [&]() {
            if (lineEditReperSortare->text() != "" && lineEditOrdineSortare->text() != "") {
                auto pesti = service.sorteaza(lineEditReperSortare->text().toInt(), lineEditOrdineSortare->text().toInt());
                updateTabelMic(pesti);
                updateTabel(pesti);
            }
            });

        QObject::connect(tabelPesti, &QTableWidget::itemClicked, [&](QTableWidgetItem* item) {
            QString nume = tabelPesti->item(item->row(), 0)->text();
            QString anotimp = tabelPesti->item(item->row(), 1)->text();
            QString vreme = tabelPesti->item(item->row(), 2)->text();
            QString locatie = tabelPesti->item(item->row(), 3)->text();
            int oraInceput = tabelPesti->item(item->row(), 4)->text().toInt();
            int oraSfarsit = tabelPesti->item(item->row(), 5)->text().toInt();
            int dificultate = tabelPesti->item(item->row(), 6)->text().toInt();
            QString prins = tabelPesti->item(item->row(), 7)->text();

            numeEdit->setText(nume);
            anotimpEdit->setText(anotimp);
            vremeEdit->setText(vreme);
            locatieEdit->setText(locatie);
            oraInceputEdit->setText(QString::number(oraInceput));
            oraSfarsitEdit->setText(QString::number(oraSfarsit));
            dificultateEdit->setText(QString::number(dificultate));
            prinsEdit->setText(prins);
            });

        QObject::connect(tabelPestiMic, &QTableWidget::itemClicked, [&](QTableWidgetItem* item) {
            QString nume = tabelPestiMic->item(item->row(), 0)->text();
            QString anotimp = tabelPestiMic->item(item->row(), 1)->text();
            QString vreme = tabelPestiMic->item(item->row(), 2)->text();
            QString locatie = tabelPestiMic->item(item->row(), 3)->text();
            int oraInceput = tabelPestiMic->item(item->row(), 4)->text().toInt();
            int oraSfarsit = tabelPestiMic->item(item->row(), 5)->text().toInt();
            int dificultate = tabelPestiMic->item(item->row(), 6)->text().toInt();
            QString prins = tabelPestiMic->item(item->row(), 7)->text();

            numeEdit->setText(nume);
            anotimpEdit->setText(anotimp);
            vremeEdit->setText(vreme);
            locatieEdit->setText(locatie);
            oraInceputEdit->setText(QString::number(oraInceput));
            oraSfarsitEdit->setText(QString::number(oraSfarsit));
            dificultateEdit->setText(QString::number(dificultate));
            prinsEdit->setText(prins);
            });

        QObject::connect(butonStergereNume, &QPushButton::clicked, [&]() {
            numeEdit->setText("");
            });

        QObject::connect(butonStergereAnotimp, &QPushButton::clicked, [&]() {
            anotimpEdit->setText("");
            });

        QObject::connect(butonStergereVreme, &QPushButton::clicked, [&]() {
            vremeEdit->setText("");
            });

        QObject::connect(butonStergereLocatie, &QPushButton::clicked, [&]() {
            locatieEdit->setText("");
            });

        QObject::connect(butonStergereOraInceput, &QPushButton::clicked, [&]() {
            oraInceputEdit->setText("");
            });

        QObject::connect(butonStergereOraSfarsit, &QPushButton::clicked, [&]() {
            oraSfarsitEdit->setText("");
            });

        QObject::connect(butonStergereDificultate, &QPushButton::clicked, [&]() {
            dificultateEdit->setText("");
            });

        QObject::connect(butonStergerePrins, &QPushButton::clicked, [&]() {
            prinsEdit->setText("");
            });

        QObject::connect(butonStergere, &QPushButton::clicked, [&]() {
            numeEdit->setText("");
            anotimpEdit->setText("");
            vremeEdit->setText("");
            locatieEdit->setText("");
            oraInceputEdit->setText("");
            oraSfarsitEdit->setText("");
            dificultateEdit->setText("");
            prinsEdit->setText("");
            });
    }
};