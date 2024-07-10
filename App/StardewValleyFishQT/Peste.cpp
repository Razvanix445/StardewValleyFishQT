#include "Peste.h"

string Peste::getNumePeste() const {
	return numePeste;
}

string Peste::getAnotimp() const {
	return anotimp;
}

string Peste::getVreme() const {
	return vreme;
}

string Peste::getLocatie() const {
	return locatie;
}

int Peste::getOraInceput() const {
	return oraInceput;
}

int Peste::getOraSfarsit() const {
	return oraSfarsit;
}

int Peste::getDificultate() const {
	return dificultate;
}

string Peste::getPrins() const {
	return prins;
}

void Peste::setAnotimp(const string anotimp) {
	this->anotimp = anotimp;
}

void Peste::setVreme(const string vreme) {
	this->vreme = vreme;
}

void Peste::setLocatie(const string locatie) {
	this->locatie = locatie;
}

void Peste::setOraInceput(const int oraInceput) {
	this->oraInceput = oraInceput;
}

void Peste::setOraSfarsit(const int oraSfarsit) {
	this->oraSfarsit = oraSfarsit;
}

void Peste::setDificultate(const int dificultate) {
	this->dificultate = dificultate;
}

void Peste::setPrins(const string prins) {
	this->prins = prins;
}