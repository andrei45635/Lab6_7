#include "offer_service.h"
#include "oferta.h"
#include <assert.h>
#include <cassert>

void ServiceOffer::addServiceOffer(string denum, string dest, string type, double price) {
	Offer ofr{ denum, dest, type, price };
	//validare oferta
	repo.addRepoOffer(ofr);
}

vector<Offer> ServiceOffer::getAllService() {
	return repo.getAll();
}

void ServiceOffer::deleteServiceOffer(int pos) {
	repo.deleteRepoOffer(pos);
}

void ServiceOffer::modifyServiceOffer(int pos, string new_denum, string new_dest, string new_type, double new_price) {
	Offer new_ofr{ new_denum, new_dest, new_type, new_price };
	//validare oferta
	repo.modifyRepoOffer(pos, new_ofr);
}

Offer ServiceOffer::findOfferService(int pos) {
	return repo.findOfferRepo(pos);
}

void testCreateService() {
	RepoOffer test_repo;
	ServiceOffer test_serv(test_repo);
	string denum = "Familie";
	string dest = "Kiev";
	string type = "Roadtrip";
	double price = 69;
	test_serv.addServiceOffer(denum, dest, type, price);
	const auto& offers = test_serv.getAllService();
	assert(offers.size() == 1);
}

void testDeleteOfferService() {
	RepoOffer test_repo;
	ServiceOffer test_serv(test_repo);
	string denum = "Familie";
	string dest = "Kiev";
	string type = "Roadtrip";
	double price = 69;
	test_serv.addServiceOffer(denum, dest, type, price);
	const auto& offers = test_serv.getAllService();
	assert(offers.size() == 1);
	test_serv.deleteServiceOffer(0);
	const auto& offers2 = test_serv.getAllService();
	assert(offers2.empty());
}

void testModifyOfferService() {
	RepoOffer test_repo;
	ServiceOffer test_serv(test_repo);
	string denum = "Familie";
	string dest = "Kiev";
	string type = "Roadtrip";
	double price = 69;
	test_serv.addServiceOffer(denum, dest, type, price);
	const auto& offers = test_serv.getAllService();
	assert(offers.size() == 1);
	string new_denum = "Business";
	string new_dest = "Odesa";
	string new_type = "Tren";
	double new_price = 169;
	test_serv.modifyServiceOffer(0, new_denum, new_dest, new_type, new_price);
	const auto& offers2 = test_serv.getAllService();
	assert(offers2.size() == 1);
	assert(offers2[0].getDenumire() == "Business");
	assert(offers2[0].getDestinatie() == "Odesa");
	assert(offers2[0].getType() == "Tren");
	assert(offers2[0].getPrice() == 169);
}

void testFindOfferService() {
	RepoOffer test_repo;
	ServiceOffer test_serv(test_repo);
	string denum = "Familie";
	string dest = "Kiev";
	string type = "Roadtrip";
	double price = 69;
	test_serv.addServiceOffer(denum, dest, type, price);
	string denum2 = "Business";
	string dest2 = "Odesa";
	string type2 = "Tren";
	double price2 = 169;
	test_serv.addServiceOffer(denum2, dest2, type2, price2);
	const auto& offers = test_serv.getAllService();
	assert(offers.size() == 2);
	const auto& found = test_serv.findOfferService(1);
	assert(found.getDenumire() == "Business");
	assert(found.getDestinatie() == "Odesa");
	assert(found.getType() == "Tren");
	assert(found.getPrice() == 169);
}