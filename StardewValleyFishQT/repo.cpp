#include "repo.h"

void Repo::adaugaPeste(const Peste& peste) {
	auto iterator = std::find_if(pesti.begin(), pesti.end(), [&](const Peste& pesteGasit) {
		return peste.getNumePeste() == pesteGasit.getNumePeste();
		});
	if (iterator != pesti.end())
		throw ExceptieRepo("Pestele " + peste.getNumePeste() + " este deja adaugat!\n");
	pesti.push_back(peste);
}

void Repo::stergePeste(const string& numePeste) {
	auto iterator = std::find_if(pesti.begin(), pesti.end(), [&](const Peste& pesteGasit) {
		return pesteGasit.getNumePeste() == numePeste;
		});
	if (iterator == pesti.end())
		throw ExceptieRepo("Pestele " + numePeste + " nu a fost gasit!\n");
	pesti.erase(iterator);
}

void Repo::modificaPeste(const Peste& pesteModificat) {
	auto iterator = std::find_if(pesti.begin(), pesti.end(), [&](const Peste& pesteGasit) {
		return pesteModificat.getNumePeste() == pesteGasit.getNumePeste();
		});
	if (iterator == pesti.end())
		throw ExceptieRepo("Pestele " + pesteModificat.getNumePeste() + " nu a fost gasit!\n");
	*iterator = pesteModificat;
}

const Peste& Repo::cautaPeste(const string& numePeste) {
	auto iterator = std::find_if(pesti.begin(), pesti.end(), [&](const Peste& pesteGasit) {
		return pesteGasit.getNumePeste() == numePeste;
		});
	if (iterator == pesti.end())
		throw ExceptieRepo("Pestele " + numePeste + " nu a fost gasit!\n");
	return *iterator;
}

const vector<Peste>& Repo::getAll() const noexcept {
	return this->pesti;
}

Repo::~Repo()
{
}

ostream& operator<<(ostream& out, const ExceptieRepo& exceptie) {
	for (const auto& mesaj : exceptie.mesajEroare)
		out << mesaj;
	return out;
}

void RepoFile::readAllFromFile() {
	std::ifstream in(numeFisier);
	if (!in.is_open()) {
		throw ExceptieRepo("Fisierul nu a putut fi deschis: " + numeFisier);
	}
	string numePeste, anotimp, vreme, locatie;
	int oraInceput, oraSfarsit, dificultate;
	while (true) {
		string numePeste;
		std::getline(in >> std::ws, numePeste);

		if (in.fail()) {
			break;
		}

		string anotimp;
		std::getline(in >> std::ws, anotimp);

		string vreme;
		std::getline(in >> std::ws, vreme);

		string locatie;
		std::getline(in >> std::ws, locatie);

		int oraInceput;
		in >> oraInceput;
		int oraSfarsit;
		in >> oraSfarsit;
		int dificultate;
		in >> dificultate;
		string prins;
		std::getline(in >> std::ws, prins);

		Peste peste{ numePeste, anotimp, vreme, locatie, oraInceput, oraSfarsit, dificultate, prins };
		Repo::adaugaPeste(peste);
	}
	in.close();
}

void RepoFile::writeAllToFile() {
	std::ofstream out(numeFisier);
	if (!out.is_open()) {
		throw ExceptieRepo("Fisierul nu a putut fi deschis: " + numeFisier);
	}
	for (auto& peste : Repo::getAll()) {
		out << peste.getNumePeste() << std::endl;
		out << peste.getAnotimp() << std::endl;
		out << peste.getVreme() << std::endl;
		out << peste.getLocatie() << std::endl;
		out << peste.getOraInceput() << std::endl;
		out << peste.getOraSfarsit() << std::endl;
		out << peste.getDificultate() << std::endl;
		out << peste.getPrins() << std::endl;
	}
	out.close();
}