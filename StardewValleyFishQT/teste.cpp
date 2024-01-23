#include "teste.h"

void ruleazaTesteDomeniuPeste() {
	Peste peste;
	peste.setAnotimp("Spring");
	peste.setVreme("Sun");
	peste.setLocatie("Ocean");
	peste.setOraInceput(2);
	peste.setOraSfarsit(6);
	peste.setDificultate(50);
	peste.setPrins("-");

	assert(peste.getAnotimp() == "Spring");
	assert(peste.getVreme() == "Sun");
	assert(peste.getLocatie() == "Ocean");
	assert(peste.getOraInceput() == 2);
	assert(peste.getOraSfarsit() == 6);
	assert(peste.getDificultate() == 50);
	assert(peste.getPrins() == "-");
}

void ruleazaTesteRepo() {
	Repo repo;
	Peste peste{ "Tuna", "Spring", "Sun", "Ocean", 2, 6, 50, "-" };
	assert(repo.getAll().size() == 0);
	repo.adaugaPeste(peste);
	try {
		repo.adaugaPeste(peste);
		assert(false);
	}
	catch (ExceptieRepo& exceptie) {
		assert(true);
	}
	assert(repo.getAll().size() == 1);

	Peste pesteGasit = repo.cautaPeste(peste.getNumePeste());
	assert(pesteGasit.getAnotimp() == "Spring");
	try {
		repo.cautaPeste("Avatar");
		assert(false);
	}
	catch (ExceptieRepo& exceptie) {
		assert(true);
	}

	Peste pesteModificat{ "Tuna", "Summer", "Sun", "Ocean", 2, 6, 50, "-" };
	Peste pesteInexistent{ "Anchovy", "Summer", "Sun", "Town River", 6, 10, 10, "-" };
	repo.modificaPeste(pesteModificat);
	try {
		repo.modificaPeste(pesteInexistent);
		assert(false);
	}
	catch (ExceptieRepo& exceptie) {
		assert(true);
	}
	assert(repo.getAll().size() == 1);
	assert(pesteModificat.getAnotimp() == "Summer");

	repo.stergePeste(pesteModificat.getNumePeste());
	try {
		repo.stergePeste(pesteModificat.getNumePeste());
		assert(false);
	}
	catch (ExceptieRepo& exceptie) {
		assert(true);
	}
	assert(repo.getAll().size() == 0);
}

void ruleazaTesteRepoFile() {
	std::ofstream fout("pestiTest.txt", std::ios::trunc);
	fout << "Tuna\n" << "Summer\n" << "Sun\n" << "Ocean\n" << "2\n" << "6\n" << "10\n" << "-\n";
	fout.close();

	RepoFile repoFile("pestiTest.txt");
	assert(repoFile.getAll()[0].getNumePeste() == "Tuna");
	assert(repoFile.getAll()[0].getAnotimp() == "Summer");
	assert(repoFile.getAll()[0].getVreme() == "Sun");
	assert(repoFile.getAll()[0].getOraInceput() == 2);
	assert(repoFile.getAll()[0].getOraSfarsit() == 6);
	assert(repoFile.getAll()[0].getDificultate() == 10);
	assert(repoFile.getAll()[0].getPrins() == "-");
}

void ruleazaTesteService() {
	Repo repo;
	Validator validator;
	Service service{ repo, validator };
	Peste peste{ "Tuna", "Spring", "Sun", "Ocean", 2, 6, 50, "-" };
	assert(service.getAll().size() == 0);
	service.adaugaPeste("Tuna", "Spring", "Sun", "Ocean", 2, 6, 50, "-");
	try {
		service.adaugaPeste("Tuna", "Spring", "Sun", "Ocean", 2, 6, 50, "-");
		assert(false);
	}
	catch (ExceptieRepo& exceptie) {
		assert(true);
	}
	assert(service.getAll().size() == 1);

	Peste pesteGasit = service.cautaPeste(peste.getNumePeste());
	assert(pesteGasit.getAnotimp() == "Spring");
	try {
		service.cautaPeste("Avatar");
		assert(false);
	}
	catch (ExceptieRepo& exceptie) {
		assert(true);
	}

	Peste pesteModificat{ "Tuna", "Summer", "Sun", "Ocean", 2, 6, 50, "-" };
	Peste pesteInexistent{ "Anchovy", "Summer", "Sun", "Town River", 6, 10, 10, "-" };
	service.modificaPeste("Tuna", "Summer", "Sun", "Ocean", 2, 6, 50, "-");
	try {
		service.modificaPeste("Anchovy", "Summer", "Sun", "Town River", 6, 10, 10, "-");
		assert(false);
	}
	catch (ExceptieRepo& exceptie) {
		assert(true);
	}
	assert(service.getAll().size() == 1);
	assert(pesteModificat.getAnotimp() == "Summer");

	service.stergePeste(pesteModificat.getNumePeste());
	try {
		service.stergePeste(pesteModificat.getNumePeste());
		assert(false);
	}
	catch (ExceptieRepo& exceptie) {
		assert(true);
	}
	assert(service.getAll().size() == 0);
}

void ruleazaTesteFiltrariSortari() {
	Repo repo;
	Validator validator;
	Service service{ repo, validator };
	Peste peste1{ "Tuna", "Spring", "Sun", "Ocean", 2, 6, 50, "-" };
	Peste peste2{ "Anchovy", "Winter", "Rain", "Mountain Lake", 3, 10, 10, "X" };
	Peste peste3{ "Largemouth Bass", "Spring", "Sun", "Town River", 4, 15, 20, "X" };
	Peste peste4{ "Sardine", "Summer", "Any", "Ginger Island River", 6, 5, 10, "-" };
	repo.adaugaPeste(peste1);
	repo.adaugaPeste(peste2);
	repo.adaugaPeste(peste3);
	repo.adaugaPeste(peste4);
	vector<Peste> pestiFiltrati1 = service.filtreazaDupaLocatieSiAnotimp("Ocean", "Spring");
	assert(pestiFiltrati1.size() == 1);
	vector<Peste> pestiFiltrati2 = service.filtreazaDupaAnotimp("Spring");
	assert(pestiFiltrati2.size() == 2);
	vector<Peste> pestiSortati = service.sorteaza(1, 2);
	assert(pestiSortati[0].getNumePeste() == "Tuna");
	assert(pestiSortati[1].getNumePeste() == "Sardine");
	assert(pestiSortati[2].getNumePeste() == "Largemouth Bass");
	assert(pestiSortati[3].getNumePeste() == "Anchovy");
}

void ruleazaToateTestele() {
	ruleazaTesteDomeniuPeste();
	ruleazaTesteRepo();
	ruleazaTesteRepoFile();
	ruleazaTesteService();
	ruleazaTesteFiltrariSortari();
}