#pragma once
#include "Peste.h"
#include <vector>
#include <string>
#include <ostream>
#include <functional>
#include <fstream>
#include <iostream>

using namespace std;

class Repo {
private:

	vector<Peste> pesti;

public:

	Repo() = default;

	Repo(const Repo& other) = delete;

	/*
	Adauga peste in repository
	arunca exceptie daca exista deja un peste cu acelasi titlu
	*/
	virtual void adaugaPeste(const Peste& peste);

	/*
	Sterge peste dupa numele din repository
	arunca exceptie daca nu s-a gasit numele pestelui
	*/
	virtual void stergePeste(const string& numePeste);

	/*
	Modifica un peste din repository
	arunca exceptie daca nu exista numele pestelui sau noile date sunt invalide
	*/
	virtual void modificaPeste(const Peste& pesteModificat);

	/*
	Cauta peste in repository
	arunca exceptie daca nu se gaseste pestele
	*/
	const Peste& cautaPeste(const string& numePeste);

	/*
	Functia getAll returneaza toti pestii din repository
	*/
	const vector<Peste>& getAll() const noexcept;

	virtual ~Repo();
};

class ExceptieRepo {

	string mesajEroare;

public:

	ExceptieRepo(string mesaj) :mesajEroare{ mesaj } {}

	friend ostream& operator<<(ostream& out, const ExceptieRepo& exceptie);

	string getMesaj() { return this->mesajEroare; }

};

ostream& operator<<(ostream& out, const ExceptieRepo& exceptie);


class RepoFile :public Repo {
private:

	void readAllFromFile();
	void writeAllToFile();
	string numeFisier;
	void clearFile() {
		std::ofstream fin(numeFisier, std::ios::trunc);
		fin.close();
	}

public:

	RepoFile(string numeFisier) :Repo(), numeFisier{ numeFisier } {
		readAllFromFile();
	}

	void adaugaPeste(const Peste& peste) override {
		Repo::adaugaPeste(peste);
		writeAllToFile();
	}

	void stergePeste(const string& numePeste) override {
		Repo::stergePeste(numePeste);
		writeAllToFile();
	}

	void modificaPeste(const Peste& peste) override {
		Repo::modificaPeste(peste);
		writeAllToFile();
	}

	~RepoFile() override {
	}
};