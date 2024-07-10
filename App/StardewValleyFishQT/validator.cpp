#include "validator.h"
#include <assert.h>
#include <sstream>

void Validator::valideazaAnotimp(const string anotimp) {
	vector<string> mesajEroare;
	if (anotimp != "Spring" && anotimp != "Summer" && anotimp != "Fall" && anotimp != "Winter") mesajEroare.push_back("Anotimp invalid!\n");
	if (!mesajEroare.empty())
		throw ExceptieValidare(mesajEroare);

}

void Validator::valideazaVreme(const string vreme) {
	vector<string> mesajEroare;
	if (vreme != "Any" && vreme != "Sun" && vreme != "Rain" && vreme != "Wind") mesajEroare.push_back("Vreme invalida!\n");
	if (!mesajEroare.empty())
		throw ExceptieValidare(mesajEroare);
}

void Validator::valideazaLocatie(const string locatie) {
	vector<string> mesajEroare;
	if (locatie != "Ocean" && locatie != "Ginger Island Oceans" && locatie != "Town River" && locatie != "Forest River" && locatie != "Mountain Lake" && locatie != "Forest Pond" && locatie != "Secret Woods Pond" && locatie != "The Sewers" && locatie != "Witch's Swamp" && locatie != "Mines lvl 20" && locatie != "Mines lvl 60" && locatie != "Mines lvl 100" && locatie != "Volcano Caldera" && locatie != "The Desert" && locatie != "Cindersap Forest Pond" && locatie != "Ginger Island Rivers" && locatie != "Mutant Bug Lair" && locatie != "Pirate Cove" && locatie != "Ginger Island Pond" && locatie != "Night Market") mesajEroare.push_back("Locatie invalida!\n");
	if (!mesajEroare.empty())
		throw ExceptieValidare(mesajEroare);
}

void Validator::valideaza(const Peste& peste) {
	vector<string> mesajEroare;
	if (peste.getNumePeste().size() == 0) mesajEroare.push_back("Nume invalid!\n");
	if (peste.getAnotimp().size() == 0) mesajEroare.push_back("Anotimp invalid!\n");
	if (peste.getVreme().size() == 0) mesajEroare.push_back("Vreme invalida!\n");
	if (peste.getLocatie().size() == 0) mesajEroare.push_back("Locatie invalida!\n");
	if (peste.getOraInceput() < 0 || peste.getOraInceput() > 24) mesajEroare.push_back("Ora inceput invalida!\n");
	if (peste.getOraSfarsit() < 0 || peste.getOraSfarsit() > 24) mesajEroare.push_back("Ora sfarsit invalida!\n");
	if (peste.getDificultate() < 0 || peste.getDificultate() > 110) mesajEroare.push_back("Dificultate invalida!\n");
	if (mesajEroare.size() > 0) {
		throw ExceptieValidare(mesajEroare);
	}
}

ostream& operator<<(ostream& out, const ExceptieValidare& exceptie) {
	for (const auto& mesaj : exceptie.mesajEroare) {
		out << mesaj << " ";
	}
	return out;
}
