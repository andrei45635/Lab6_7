#pragma once

#include "oferta.h"
#include "VectDinamic.h"
#include <vector>

using std::vector;

/*
* Clasa RepoException
* Intoarce un mesaj de eroare daca este cazul
*/
class RepoException {
private:

	string mesg;

public:

	/*
	* Constructor pentru clasa RepoException
	* Primeste atributul string msg = mesajul erorii
	*/
	RepoException(string msg) : mesg{ msg } {

	}

	/*
	* getter pentru mesaj
	*/
	string getMessage();

};

class RepoOffer {
private:
	
	/*
	* Lista cu oferte din repo, reprezentata pe vector dinamic din STL
	*/
	VectDinamic<Offer> offers;
	//vector<Offer> offers;

public:

	/*
	* Adauga oferte in repo
	* pre: ofr = oferta
	* post: oferta a fost adaugata in repo
	*/
	void addRepoOffer(const Offer& ofr);

	/*
	* Nu permitem copierea de obiecte
	*/
	RepoOffer(const RepoOffer& ot) = delete;
	RepoOffer() = default;

	/*
	* getter pentru toate ofertele
	*/
	const VectDinamic<Offer>& getAll();
	//const vector<Offer>& getAll();
	
	/*
	* Sterge oferta din repo
	* pre: pos = pozitia din repo
	* post: oferta a fost stearsa
	*/
	void deleteRepoOffer(int pos);

	/*
	* Modifica oferta din repo
	* pre: pos = pozitia din repo 
	*	   new_ofr = oferta noua cu care se va inlocui
	* post: oferta a fost modificata
	*/
	void modifyRepoOffer(int pos, const Offer& new_ofr);

	/*
	* Returneaza oferta de pe pozitia cautata
	* pre: pos = pozitia cautata
	* post: oferta de pe pozitia cautata
	*/
	Offer findOfferRepo(int pos);
};

void test_create_repo();
void test_delete_repo();
void test_modify_repo();
void test_find_repo();