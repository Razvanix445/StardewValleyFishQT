#pragma once

#include "Peste.h"
#include "repo.h"
#include "validator.h"
#include <string>
#include <vector>
#include <functional>

using std::vector;
using std::function;

class Service {
private:

	Repo& repository;
	Validator& validator;

public:

	Service(Repo& repository, Validator& validator) noexcept : repository{ repository }, validator{ validator } {}
	//nu permitem copierea de obiecte Service
	Service(const Service& other) = delete;

	/*
	Functia creeaza, valideaza si adauga un nou peste in repository
	arunca exceptie daca parametrii pestelui nu sunt valizi sau daca exista deja un peste cu acelasi nume
	*/
	void adaugaPeste(const string& numePeste, const string& anotimp, const string& vreme, const string& locatie, const int oraInceput, const int oraSfarsit, const int dificultate, const string& prins);

	/*
	Functia sterge un peste din repository
	arunca exceptie daca nu s-a gasit numele pestelui
	*/
	void stergePeste(const string& numePeste);

	/*
	Functia modifica un peste din repository
	arunca exceptie daca nu s-a gasit numele pestelui
	*/
	void modificaPeste(const string& numePeste, const string& anotimp, const string& vreme, const string& locatie, const int oraInceput, const int oraSfarsit, const int dificultate, const string& prins);

	/*
	Functia cauta un peste in repository dupa numele acestuia
	arunca exceptie daca nu s-a gasit numele pestelui
	*/
	const Peste& cautaPeste(const string& numePeste) const;

	/*
	Functia returneaza toti pestii in ordinea adaugarii lor in repository
	*/
	const vector<Peste>& getAll() const;

	vector<Peste> filtreazaDupaLocatieSiAnotimp(const string& locatie, const string& anotimp);

	vector<Peste> filtreazaDupaAnotimp(const string& anotimp);

	vector<Peste> filtreazaDupaPrinsNeprins(const string& prins, vector<Peste> pesti);

	string sorteazaString(const string& sirDeCuvinte);

	vector<Peste> sorteaza(int reperSortare, int ordineSortare);

	void exportaInHTML(const vector<Peste>& pesti);

	~Service();

};