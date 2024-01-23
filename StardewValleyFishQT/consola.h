#pragma once
#include "service.h"
#include "Peste.h"

class UI {
private:

	Service& service;

	/*
	Citeste datele de la tastatura si adauga peste nou in repository
	arunca exceptie daca parametrii nu sunt valizi sau numele pestelui este deja existent
	*/
	void ui_adaugaPeste();

	/*
	Sterge un peste din repository
	*/
	void ui_stergePeste();

	/*
	Modifica un peste din repository
	*/
	void ui_modificaPeste();

	/*
	Afiseaza lista de pesti din repository
	*/
	void ui_afiseazaPesti(const vector<Peste>& pesti);

	/*
	Cauta un peste dupa numele acestuia
	*/
	void ui_cautaPeste();

	/*
	Filtreaza pesti dupa anotimp
	*/
	void ui_filtrare();

	/*
	Sorteaza pesti dupa nume / locatie / ora de inceput
	*/
	void ui_sortare();

	void ui_marcheazaPeste();

public:
	UI(Service& service) :service{ service } {}
	//nu permitem copierea obiectelor
	UI(const UI& other) = delete;

	~UI();

	void ui_meniu();

	void ruleaza();

};