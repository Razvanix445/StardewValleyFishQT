#pragma once
#include <iostream>
#include <string>
using std::string;
using std::cout;

class Peste {

private:

	string numePeste;
	string anotimp;
	string vreme;
	string locatie;
	int oraInceput;
	int oraSfarsit;
	int dificultate;
	string prins;

public:

	string getNumePeste() const;

	string getAnotimp() const;

	string getVreme() const;

	string getLocatie() const;

	int getOraInceput() const;

	int getOraSfarsit() const;

	int getDificultate() const;

	string getPrins() const;

	void setAnotimp(const string anotimp);

	void setVreme(const string vreme);

	void setLocatie(const string locatie);

	void setOraInceput(const int oraInceput);

	void setOraSfarsit(const int oraSfarsit);

	void setDificultate(const int dificultate);

	void setPrins(const string prins);

	Peste() : numePeste{ "" }, anotimp{ "" }, vreme{ "" }, locatie{ "" }, oraInceput{ 0 }, oraSfarsit{ 0 }, dificultate{ 0 }, prins{ "" } {}

	Peste(const string numePeste, const string anotimp, const string vreme, const string locatie, const int oraInceput, const int oraSfarsit, const int dificultate, const string prins) : numePeste{ numePeste }, anotimp{ anotimp }, vreme{ vreme }, locatie{ locatie }, oraInceput{ oraInceput }, oraSfarsit{ oraSfarsit }, dificultate{ dificultate }, prins{ prins } {}

};