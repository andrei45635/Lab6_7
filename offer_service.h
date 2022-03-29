#pragma once
#include "oferta.h"
#include "offer_repo.h"

/*
* Clasa ServiceOffer
* Service-ul ofertelor, primeste ca atribut repo-ul
*/
class ServiceOffer {
private:
	RepoOffer& repo;

public:
	/*
	* Constructor
	*/
	ServiceOffer(RepoOffer& repo) : repo{ repo } {

	}

	ServiceOffer(const ServiceOffer& ot) = delete;
	ServiceOffer() = default;
	/*
	* Adauga in service ofertele
	* pre: 
	* -> string denum: denumirea ofertei
	* -> string dest: destinatia ofertei
	* -> string type: tipul ofertei
	* -> double price: pretul ofertei
	* post: oferta a fost adaugata in service
	*/
	void addServiceOffer(string denum, string dest, string type, double price);

	/*
	* Sterge oferta din service
	* pre: pos = pozitia din repo
	* post: oferta a fost stearsa
	*/
	void deleteServiceOffer(int pos);

	/*
	* Modifica oferta din service
	* pre: pos = pozitia din repo
	*	   string new_denum: noua denumire
	*	   string new_dest: noua destinatie
	*      string new_type: noul tip
	*      double new_price: noul pret
	* post: oferta a fost modificata
	*/
	void modifyServiceOffer(int pos, string new_denum, string new_dest, string new_type, double new_price);

	Offer findOfferService(int pos);

	/*
	* getter pentru ofertele din service
	*/
	vector<Offer> getAllService();
};

void testCreateService();
void testDeleteOfferService();
void testModifyOfferService();
void testFindOfferService();