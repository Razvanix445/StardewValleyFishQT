#include "consola.h"
#include "Peste.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;

//constexpr int Optiune_Adaugare_Peste = 1;
//constexpr int Optiune_Stergere_Peste = 2;
//constexpr int Optiune_Modificare_Peste = 3;
constexpr int Optiune_Afisare_Pesti = 1;
constexpr int Optiune_Cautare_Peste = 2;
constexpr int Optiune_Filtrare_Peste = 3;
constexpr int Optiune_Sortare_Peste = 4;
constexpr int Optiune_Peste_Prins = 5;
constexpr int Optiune_Iesire = 0;

void UI::ui_adaugaPeste() {
	int oraInceput, oraSfarsit, dificultate, numarAuxiliar = 0;
	string numePeste, anotimp, vreme, locatie, altAnotimp, altaVreme, altaLocatie, prins;
	cin.ignore();
	cout << "Introduceti numele pestelui: ";
	getline(cin, numePeste);

	cout << "Introduceti in cate anotimpuri se gaseste pestele: ";
	cin >> numarAuxiliar;
	cin.ignore();
	if (numarAuxiliar > 1) {
		for (int i = 1; i <= numarAuxiliar; i++) {
			cout << "Introduceti anotimpul " << i << " in care se gaseste pestele " + numePeste + ": ";
			getline(cin, altAnotimp);
			//service.valideazaAnotimp(altAnotimp);
			anotimp = anotimp + altAnotimp + "/";
		}
		anotimp.pop_back();
		anotimp = service.sorteazaString(anotimp);
	}
	else {
		cout << "Introduceti anotimpul in care se gaseste pestele " + numePeste + ": ";
		getline(cin, anotimp);
		//service.valideazaAnotimp(anotimp);
	}

	cout << "Introduceti in timpul cator diferite fenomene meteorologice se gaseste pestele " + numePeste + ": ";
	cin >> numarAuxiliar;
	cin.ignore();
	if (numarAuxiliar > 1) {
		for (int i = 1; i <= numarAuxiliar; i++) {
			cout << "Introduceti vremea (fenomenul) " << i << " in timpul careia se gaseste pestele " + numePeste + ": ";
			getline(cin, altaVreme);
			//service.valideazaVreme(altaVreme);
			vreme = vreme + altaVreme + "/";
		}
		vreme.pop_back();
		vreme = service.sorteazaString(vreme);
	}
	else {
		cout << "Introduceti vremea (fenomenul) in timpul careia se gaseste pestele " + numePeste + ": ";
		getline(cin, vreme);
		//service.valideazaVreme(vreme);
	}

	cout << "Introduceti numarul de locatii in care se gaseste pestele " + numePeste + ": ";
	cin >> numarAuxiliar;
	cin.ignore();
	if (numarAuxiliar > 1) {
		for (int i = 1; i <= numarAuxiliar; i++) {
			cout << "Introduceti locatia " << i << " unde se gaseste pestele " + numePeste + ": ";
			getline(cin, altaLocatie);
			//service.valideazaLocatie(altaLocatie);
			locatie = locatie + altaLocatie + "/";
		}
		locatie.pop_back();
		locatie = service.sorteazaString(locatie);
	}
	else {
		cout << "Introduceti locatia unde se gaseste pestele " + numePeste + ": ";
		getline(cin, locatie);
		//service.valideazaLocatie(locatie);
	}

	cout << "Introduceti ora la care incepe sa apara pestele " + numePeste + ": ";
	cin >> oraInceput;
	cin.ignore();

	cout << "Introduceti ora la care nu mai apare pestele " + numePeste + ": ";
	cin >> oraSfarsit;
	cin.ignore();

	cout << "Introduceti dificultatea de prindere a pestelui: ";
	cin >> dificultate;
	cin.ignore();

	service.adaugaPeste(numePeste, anotimp, vreme, locatie, oraInceput, oraSfarsit, dificultate, prins);
	cout << "Pestele " << numePeste << " a fost adaugat cu succes!\n";
}

void UI::ui_stergePeste() {
	string numePeste;
	cin.ignore();
	cout << "Introduceti numele pestelui pentru stergere: ";
	getline(cin, numePeste);
	service.stergePeste(numePeste);
	cout << "Pestele " << numePeste << " a fost sters cu succes!\n";
}

void UI::ui_modificaPeste() {
	int oraInceput, oraSfarsit, dificultate, numarAuxiliar = 0;
	string numePeste, anotimp, vreme, locatie, altAnotimp, altaVreme, altaLocatie, prins;
	cin.ignore();
	cout << "Introduceti numele pestelui pentru modificare: ";
	getline(cin, numePeste);

	cout << "Introduceti in cate anotimpuri se gaseste pestele: ";
	cin >> numarAuxiliar;
	cin.ignore();
	if (numarAuxiliar > 1) {
		for (int i = 1; i <= numarAuxiliar; i++) {
			cout << "Introduceti anotimpul " << i << " in care se gaseste pestele " + numePeste + ": ";
			getline(cin, altAnotimp);
			//service.valideazaAnotimp(altAnotimp);
			anotimp = anotimp + altAnotimp + "/";
		}
		anotimp.pop_back();
		anotimp = service.sorteazaString(anotimp);
	}
	else {
		cout << "Introduceti anotimpul in care se gaseste pestele " + numePeste + ": ";
		getline(cin, anotimp);
		//service.valideazaAnotimp(anotimp);
	}

	cout << "Introduceti in timpul cator diferite fenomene meteorologice se gaseste pestele " + numePeste + ": ";
	cin >> numarAuxiliar;
	cin.ignore();
	if (numarAuxiliar > 1) {
		for (int i = 1; i <= numarAuxiliar; i++) {
			cout << "Introduceti vremea (fenomenul) " << i << " in timpul careia se gaseste pestele " + numePeste + ": ";
			getline(cin, altaVreme);
			//service.valideazaVreme(altaVreme);
			vreme = vreme + altaVreme + "/";
		}
		vreme.pop_back();
		vreme = service.sorteazaString(vreme);
	}
	else {
		cout << "Introduceti vremea (fenomenul) in timpul careia se gaseste pestele " + numePeste + ": ";
		getline(cin, vreme);
		//service.valideazaVreme(vreme);
	}

	cout << "Introduceti numarul de locatii in care se gaseste pestele " + numePeste + ": ";
	cin >> numarAuxiliar;
	cin.ignore();
	if (numarAuxiliar > 1) {
		for (int i = 1; i <= numarAuxiliar; i++) {
			cout << "Introduceti locatia " << i << " unde se gaseste pestele " + numePeste + ": ";
			getline(cin, altaLocatie);
			//service.valideazaLocatie(altaLocatie);
			locatie = locatie + altaLocatie + "/";
		}
		locatie.pop_back();
		locatie = service.sorteazaString(locatie);
	}
	else {
		cout << "Introduceti locatia unde se gaseste pestele " + numePeste + ": ";
		getline(cin, locatie);
		//service.valideazaLocatie(locatie);
	}

	cout << "Introduceti ora la care incepe sa apara pestele " + numePeste + ": ";
	cin >> oraInceput;
	cin.ignore();

	cout << "Introduceti ora la care nu mai apare pestele " + numePeste + ": ";
	cin >> oraSfarsit;
	cin.ignore();

	cout << "Introduceti dificultatea de prindere a pestelui: ";
	cin >> dificultate;
	cin.ignore();

	service.modificaPeste(numePeste, anotimp, vreme, locatie, oraInceput, oraSfarsit, dificultate, prins);
	cout << "Pestele " << numePeste << " a fost modificat cu succes!\n";
}

void UI::ui_afiseazaPesti(const vector<Peste>& pesti) {
	string oraInceput, oraSfarsit;
	if (pesti.size() == 0) {
		cout << "\nNu exista pesti in lista!\n";
		return;
	}
	cout << "Pesti: \n";
	cout << "=================================\n";
	int i = 0;
	for (const auto& peste : pesti) {
		i++;
		if (peste.getOraInceput() <= 12)
			oraInceput = std::to_string(peste.getOraInceput()) + "AM";
		else
			oraInceput = std::to_string(peste.getOraInceput() - 12) + "PM";
		if (peste.getOraSfarsit() <= 12)
			oraSfarsit = std::to_string(peste.getOraSfarsit()) + "AM";
		else
			oraSfarsit = std::to_string(peste.getOraSfarsit() - 12) + "PM";
		cout << i << ". " << peste.getNumePeste() << "; Anotimpuri: " << peste.getAnotimp() << "; Vreme: " << peste.getVreme() << "; Locatii: " << peste.getLocatie() << "; Timp: " << oraInceput << " -> " << oraSfarsit << "; Dificultate: " << peste.getDificultate() << "; Prins: " << peste.getPrins() << "\n";
	}
	cout << "=================================\n";
}

void UI::ui_cautaPeste() {
	string numePeste, oraInceput, oraSfarsit;
	cin.ignore();
	cout << "Introduceti numele pestelui cautat: ";
	getline(cin, numePeste);
	Peste peste = service.cautaPeste(numePeste);
	if (peste.getOraInceput() <= 12)
		oraInceput = std::to_string(peste.getOraInceput()) + "AM";
	else
		oraInceput = std::to_string(peste.getOraInceput() - 12) + "PM";
	if (peste.getOraSfarsit() <= 12)
		oraSfarsit = std::to_string(peste.getOraSfarsit()) + "AM";
	else
		oraSfarsit = std::to_string(peste.getOraSfarsit() - 12) + "PM";
	cout << peste.getNumePeste() << "; Anotimpuri: " << peste.getAnotimp() << "; Vreme: " << peste.getVreme() << "; Locatii: " << peste.getLocatie() << "; Timp: " << oraInceput << " -> " << oraSfarsit << "; Dificultate: " << peste.getDificultate() << "; Prins: " << peste.getPrins() << "\n";
}

void UI::ui_filtrare() {
	// 1 -> anotimp / 2 -> locatie + anotimp / 0 -> iesire (sunt optiunile utilizatorului)
	int reperFiltrare;
	cin.ignore();
	cout << "Alegeti reperul de filtrare (1 -> anotimp / 2 -> locatie + anotimp / 0 -> iesire): ";
	cin >> reperFiltrare;
	if (reperFiltrare == 1) {
		string anotimp;
		cout << "Introduceti anotimpul dupa care sa se filtreze: ";
		cin.ignore();
		getline(cin, anotimp);
		ui_afiseazaPesti(service.filtreazaDupaAnotimp(anotimp));
	}
	else if (reperFiltrare == 2) {
		string locatie;
		cout << "Introduceti locatia dupa care sa se filtreze: ";
		cin.ignore();
		getline(cin, locatie);
		string anotimp;
		cout << "Introduceti anotimpul dupa care sa se filtreze: ";
		cin.ignore();
		getline(cin, anotimp);
		ui_afiseazaPesti(service.filtreazaDupaLocatieSiAnotimp(locatie, anotimp));
	}
	else if (reperFiltrare == 0) return;
	else {
		cout << "Reper de filtrare necunoscut!\n";
		ui_filtrare();
	}
}

void UI::ui_sortare() {
	// 1 -> nume / 2 -> locatie / 3 -> ora de inceput / 0 -> iesire (pentru reperul de sortare) -> prima optiune a utilizatorului
	// 1 -> crescator / 2 -> descrescator (pentru ordinea de sortare) -> a doua optiune a utilizatorului
	int reperSortare, ordineSortare;
	cin.ignore();
	cout << "Alegeti reperul dupa care sa se sorteze (1 -> nume / 2 -> locatie / 3 -> ora de inceput / 0 -> iesire): ";
	cin >> reperSortare;
	if (reperSortare == 0) return;
	if (reperSortare != 1 && reperSortare != 2 && reperSortare != 3) {
		cout << "Reper invalid! Va rugam sa introduceti 1, 2 sau 3!\n";
		ui_sortare();
	}
	cout << "Alegeti ordinea de sortare (1 -> crescator / 2 -> descrescator): ";
	cin >> ordineSortare;
	if (ordineSortare != 1 && ordineSortare != 2) {
		cout << "Ordine de sortare invalida! Va rugam sa introduceti 1 sau 2!\n";
		ui_sortare();
	}
	vector<Peste> pesti = service.sorteaza(reperSortare, ordineSortare);
	ui_afiseazaPesti(pesti);
}

void UI::ui_marcheazaPeste() {
	string numePeste;
	int marcat;
	cin.ignore();
	cout << "Introduceti numele pestelui: ";
	getline(cin, numePeste);
	cout << "Introduceti 1 pentru peste prins sau 0 pentru peste neprins: ";
	cin >> marcat;
	//service.marcheazaPeste(numePeste, marcat);
	cout << "Pestele " + numePeste + " a fost marcat cu succes!\n";
}

void UI::ruleaza() {
	/*
	service.adaugaFilm("John Wick: Chapter 4", "Actiune", 2023, "Keanu Reeves");
	service.adaugaFilm("The Imitation Game", "Historic Drama", 2014, "Benedict Cumberbatch");
	service.adaugaFilm("Titanic", "Epic Romance", 1997, "Leonardo DiCaprio");
	service.adaugaFilm("Avatar 2", "Science-Fiction", 2022, "Sam Worthington");
	service.adaugaFilm("The Revenant", "American Action Drama", 2016, "Leonardo DiCaprio");
	*/
	/*
	service.adaugaFilm("John Wick: Chapter 4", "Actiune", 2020, "Keanu Reeves");
	service.adaugaFilm("The Imitation Game", "Drama", 2021, "Benedict Cumberbatch");
	service.adaugaFilm("Titanic", "Romance", 2020, "Leonardo DiCaprio");
	service.adaugaFilm("Avatar 2", "Actiune", 2022, "Sam Worthington");
	service.adaugaFilm("The Revenant", "Drama", 2022, "Leonardo DiCaprio");
	*/
	while (true) {
		cout << "\n=================================\n";
		cout << "   Meniu gestionare pesti: \n";
		//cout << "1. Adauga peste.\n";
		//cout << "2. Sterge peste.\n";
		//cout << "3. Modifica peste.\n";
		cout << "1. Afiseaza toti pestii adaugati.\n";
		cout << "2. Cauta un peste dupa nume.\n";
		cout << "3. Filtreaza pesti dupa anotimp.\n";
		cout << "4. Sorteaza pesti dupa nume / locatie / ora de inceput.\n";
		cout << "5. Seteaza peste ca prins sau neprins.\n";
		cout << "0. Iesire din aplicatie.\n";
		cout << "=================================\n";
		int comanda;
		cout << ">>>";
		cin >> comanda;
		try {
			switch (comanda) {
				//case Optiune_Adaugare_Peste:
					//ui_adaugaPeste();
					//break;
				//case Optiune_Stergere_Peste:
					//ui_stergePeste();
					//break;
				//case Optiune_Modificare_Peste:
					//ui_modificaPeste();
					//break;
			case Optiune_Afisare_Pesti:
				ui_afiseazaPesti(service.getAll());
				break;
			case Optiune_Cautare_Peste:
				ui_cautaPeste();
				break;
			case Optiune_Filtrare_Peste:
				ui_filtrare();
				break;
			case Optiune_Sortare_Peste:
				ui_sortare();
				break;
			case Optiune_Peste_Prins:
				ui_marcheazaPeste();
				break;
			case Optiune_Iesire:
				return;
			default:
				cout << "Comanda necunoscuta!\n";
			}
			cout << '\n';
		}
		catch (const ExceptieRepo& exceptie) {
			cout << exceptie << "\n";
		}
		catch (const ExceptieValidare& exceptie) {
			cout << exceptie << "\n";
		}
	}
}

UI::~UI()
{
}