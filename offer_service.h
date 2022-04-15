#pragma once
#include "oferta.h"
#include "offer_repo.h"
#include "validator.h"
#include "Wishlist.h"
#include <functional>

/*
* Clasa ServiceOffer
* Service-ul ofertelor, primeste ca atribut repo-ul
*/
class ServiceOffer {
private:
	RepoOffer& repo;
	OfferValidator& valid;
	Wishlist& wish;

public:
	/*
	* Constructor
	*/
	ServiceOffer(RepoOffer& repo, OfferValidator& valid, Wishlist& wish) : repo{ repo }, valid{ valid }, wish{ wish } {
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
	const vector<Offer>& getAllService();

	vector<Offer> filter(std::function<bool(const Offer&)> fct);

	//VectDinamic<Offer>& filter_price(int price);
	vector<Offer> filtrare_pret(int price);

	vector<Offer> filtrare_dest(string dest);

	vector<Offer> generalSort(bool(*cmpMic)(const Offer& ofr1, const Offer& ofr2));

	bool sortByType(const Offer& ofr1, const Offer& ofr2);

	vector<Offer> sortDenumire();

	vector<Offer> sortDest();

	vector<Offer> sortFinal();

	void delete_from_wishlist();

	void add_to_wishlist(const string& destinatie);

	void generate_random_offers(int number);

	vector<Offer> get_all_from_wish();
};

void testCreateService();
void testDeleteOfferService();
void testModifyOfferService();
void testFindOfferService();
//void testFilterPrice();
void testFilters();
void testSorts();
void testAddCart();
void testDeleteFromCart();
void testGenerateRandom();