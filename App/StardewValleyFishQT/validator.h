#pragma once
#include "Peste.h"
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::ostream;

class ExceptieValidare {

	vector<string> mesajEroare;

public:

	ExceptieValidare(vector<string> erori) :mesajEroare{ erori } {}
	friend ostream& operator<<(ostream& out, const ExceptieValidare& exceptie);

	vector<string> getMesaj() { return mesajEroare; }
};

ostream& operator<<(ostream& out, const ExceptieValidare& exceptie);

class Validator {
public:

	void valideaza(const Peste& peste);

	void valideazaAnotimp(const string anotimp);

	void valideazaVreme(const string vreme);

	void valideazaLocatie(const string locatie);
};
