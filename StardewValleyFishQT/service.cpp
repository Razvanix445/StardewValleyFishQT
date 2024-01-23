#include "service.h"
#include <functional>
#include <algorithm>
#include <assert.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

/*
	Functia creeaza, valideaza si adauga un nou peste in repository
	arunca exceptie daca parametrii pestelui nu sunt valizi sau daca exista deja un peste cu acelasi nume
*/
void Service::adaugaPeste(const string& numePeste, const string& anotimp, const string& vreme, const string& locatie, const int oraInceput, const int oraSfarsit, const int dificultate, const string& prins) {
	const Peste peste{ numePeste, anotimp, vreme, locatie, oraInceput, oraSfarsit, dificultate, prins };
	//validator.valideazaAnotimp(anotimp);
	//validator.valideazaVreme(vreme);
	//validator.valideazaLocatie(locatie);
	validator.valideaza(peste);
	repository.adaugaPeste(peste);
}

void Service::stergePeste(const string& numePeste) {
	repository.stergePeste(numePeste);
}

void Service::modificaPeste(const string& numePeste, const string& anotimp, const string& vreme, const string& locatie, const int oraInceput, const int oraSfarsit, const int dificultate, const string& prins) {
	const Peste peste{ numePeste, anotimp, vreme, locatie, oraInceput, oraSfarsit, dificultate, prins };
	//validator.valideazaAnotimp(anotimp);
	//validator.valideazaVreme(vreme);
	//validator.valideazaLocatie(locatie);
	validator.valideaza(peste);
	repository.modificaPeste(peste);
}

const Peste& Service::cautaPeste(const string& numePeste) const {
	return repository.cautaPeste(numePeste);
}

const vector<Peste>& Service::getAll() const {
	return repository.getAll();
}

vector<Peste> Service::filtreazaDupaLocatieSiAnotimp(const string& locatie, const string& anotimp) {
	vector<Peste> pestiFiltrati;
	vector<Peste> pesti = repository.getAll();

	auto iterator = std::copy_if(pesti.begin(), pesti.end(), back_inserter(pestiFiltrati), [&](const Peste& peste) {
		return peste.getLocatie().find(locatie) != string::npos && peste.getAnotimp().find(anotimp) != string::npos;
		});

	std::sort(pestiFiltrati.begin(), pestiFiltrati.end(), [](const Peste& peste1, const Peste& peste2) {
		return peste1.getOraInceput() < peste2.getOraInceput();
		});

	//exportaInHTML(pestiFiltrati);
	return pestiFiltrati;
}

vector<Peste> Service::filtreazaDupaAnotimp(const string& anotimp) {
	vector<Peste> pestiFiltrati;
	vector<Peste> pesti = repository.getAll();

	auto iterator = std::copy_if(pesti.begin(), pesti.end(), back_inserter(pestiFiltrati), [&](const Peste& peste) {
		return peste.getAnotimp().find(anotimp) != string::npos;
		});

	//exportaInHTML(pestiFiltrati);
	return pestiFiltrati;
}

vector<Peste> Service::filtreazaDupaPrinsNeprins(const string& prins, vector<Peste> pesti) {
	vector<Peste> pestiFiltrati;

	auto iterator = std::copy_if(pesti.begin(), pesti.end(), back_inserter(pestiFiltrati), [&](const Peste& peste) {
		return peste.getPrins() == prins;
		});

	//exportaInHTML(pestiFiltrati);
	return pestiFiltrati;
}

bool comparareDupaNumeCrescator(const Peste& peste1, const Peste& peste2) {
	return peste1.getNumePeste() < peste2.getNumePeste();
}

bool comparareDupaLocatieCrescator(const Peste& peste1, const Peste& peste2) {
	return peste1.getLocatie() < peste2.getLocatie();
}

bool comparareDupaOraInceputCrescator(const Peste& peste1, const Peste& peste2) {
	return peste1.getOraInceput() < peste2.getOraInceput();
}

bool comparareDupaNumeDescrescator(const Peste& peste1, const Peste& peste2) {
	return peste1.getNumePeste() > peste2.getNumePeste();
}

bool comparareDupaLocatieDescrescator(const Peste& peste1, const Peste& peste2) {
	return peste1.getLocatie() > peste2.getLocatie();
}

bool comparareDupaOraInceputDescrescator(const Peste& peste1, const Peste& peste2) {
	return peste1.getOraInceput() > peste2.getOraInceput();
}

string Service::sorteazaString(const string& sirDeCuvinte) {
	vector<string> cuvinte;
	cout << sirDeCuvinte << std::endl;
	std::istringstream iss(sirDeCuvinte);
	string cuvant;
	while (getline(iss, cuvant, '/')) {
		cuvinte.push_back(cuvant + "/");
	}
	std::sort(cuvinte.begin(), cuvinte.end());
	std::ostringstream oss;
	for (auto it = cuvinte.begin(); it != cuvinte.end(); ++it) {
		oss << *it;
	}
	string stringSortat = oss.str();
	stringSortat.erase(stringSortat.length() - 1);
	cout << stringSortat << std::endl;
	return stringSortat;
}

vector<Peste> Service::sorteaza(int reperSortare, int ordineSortare) {

	vector<Peste> pesti = repository.getAll();

	bool(*functieDeComparare)(const Peste& peste1, const Peste& peste2) { comparareDupaNumeCrescator };

	if (reperSortare == 1) {
		if (ordineSortare == 1)
			functieDeComparare = comparareDupaNumeCrescator;
		else
			functieDeComparare = comparareDupaNumeDescrescator;
	}
	else if (reperSortare == 2) {
		if (ordineSortare == 1)
			functieDeComparare = comparareDupaLocatieCrescator;
		else
			functieDeComparare = comparareDupaLocatieDescrescator;
	}
	else if (reperSortare == 3) {
		if (ordineSortare == 1)
			functieDeComparare = comparareDupaOraInceputCrescator;
		else
			functieDeComparare = comparareDupaOraInceputDescrescator;
	}
	
	std::sort(pesti.begin(), pesti.end(), functieDeComparare);

	//exportaInHTML(pesti);
	return pesti;
}

void Service::exportaInHTML(const vector<Peste>& pesti) {
	string oraInceput, oraSfarsit;
	std::ofstream fout("pesti.html");
	if (!fout.is_open()) {
		throw ExceptieRepo("Fisierul nu a putut fi deschis!\n");
	}
	fout << "<html><body>\n";
	fout << "<table border=\"1\" style=\"width:100 % \">\n";
	for (const auto& peste : pesti) {
		fout << "<tr>\n";
		fout << "<td>" << peste.getNumePeste() << "</td>\n";
		fout << "<td>" << peste.getAnotimp() << "</td>\n";
		fout << "<td>" << peste.getVreme() << "</td>\n";
		fout << "<td>" << peste.getLocatie() << "</td>\n";
		if (peste.getOraInceput() <= 12)
			oraInceput = std::to_string(peste.getOraInceput()) + "AM";
		else
			oraInceput = std::to_string(peste.getOraInceput() - 12) + "PM";
		if (peste.getOraSfarsit() <= 12)
			oraSfarsit = std::to_string(peste.getOraSfarsit()) + "AM";
		else
			oraSfarsit = std::to_string(peste.getOraSfarsit() - 12) + "PM";
		fout << "<td>" << oraInceput << "->" << oraSfarsit << "</td>\n";
		fout << "<td>" << peste.getDificultate() << "</td>\n";
		fout << "<td>" << peste.getPrins() << "</td>\n";
		fout << "</tr>\n";
	}
	fout << "</table>\n";
	fout << "</body></html>\n";
	fout.close();
}

Service::~Service()
{
}
