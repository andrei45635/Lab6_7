#include "offer_service.h"
//#include "oferta.h"
//#include "validator.h"
#include <assert.h>
#include <algorithm>
#include <cassert>
#include <iostream>

//TODO: Implement Validator

void ServiceOffer::addServiceOffer(string denum, string dest, string type, double price) {
	Offer ofr{ denum, dest, type, price };
	//validare oferta
	valid.validate_offer(ofr);
	repo.addRepoOffer(ofr);
}

const VectDinamic<Offer>& ServiceOffer::getAllService() {
	return repo.getAll();
}

void ServiceOffer::deleteServiceOffer(int pos) {
	repo.deleteRepoOffer(pos);
}

void ServiceOffer::modifyServiceOffer(int pos, string new_denum, string new_dest, string new_type, double new_price) {
	Offer new_ofr{ new_denum, new_dest, new_type, new_price };
	//validare oferta
	valid.validate_offer(new_ofr);
	repo.modifyRepoOffer(pos, new_ofr);
}

Offer ServiceOffer::findOfferService(int pos) {
	return repo.findOfferRepo(pos);
}

VectDinamic<Offer> ServiceOffer::filter(std::function<bool(const Offer&)> fct) {
	VectDinamic<Offer> res;
	auto offers = repo.getAll();
	for (const auto& ofr : offers) {
		if (fct(ofr)) {
			res.add(ofr);
		}
	}
	return res;
}

VectDinamic<Offer> ServiceOffer::filtrare_pret(int price) {
	return filter([=](const Offer& ofr) { return ofr.getPrice() == price; });
}

VectDinamic<Offer> ServiceOffer::filtrare_dest(string dest) {
	return filter([=](const Offer& ofr) { return ofr.getDestinatie() == dest; });
}

VectDinamic<Offer> ServiceOffer::generalSort(bool(*cmpMic)(const Offer& ofr1, const Offer& ofr2)) {
	VectDinamic<Offer> res{ repo.getAll() };
	for (size_t i = 0; i < res.getSize(); i++) {
		for (size_t j = i; j < res.getSize(); j++) {
			if (!cmpMic(res.getElem(i), res.getElem(j))) {
				Offer aux = res.getElem(i);
				res.getElem(i) = res.getElem(j);
				res.getElem(j) = aux;
			}
		}
	}
	return res;
}

bool ServiceOffer::sortByType(const Offer& ofr1, const Offer& ofr2) {
	return ofr1.getType() < ofr2.getType();
}

VectDinamic<Offer> ServiceOffer::sortDenumire() {
	//return generalSort(sortByType);
	return generalSort([](const Offer& ofr1, const Offer& ofr2) { return (ofr1.getDenumire() < ofr2.getDenumire()); });
}

VectDinamic<Offer> ServiceOffer::sortDest() {
	//return generalSort(sortByType);
	return generalSort([](const Offer& ofr1, const Offer& ofr2) { return (ofr1.getDestinatie() < ofr2.getDestinatie()); });
}

VectDinamic<Offer> ServiceOffer::sortFinal() {
	VectDinamic<Offer> typed = generalSort([](const Offer& ofr1, const Offer& ofr2) { return (ofr1.getType() < ofr2.getType()); });
	VectDinamic<Offer> priced = typed;
	priced = generalSort([](const Offer& ofr1, const Offer& ofr2) {return ofr1.getPrice() < ofr2.getPrice(); });
	return priced;
}

void testCreateService() {
	RepoOffer test_repo;
	OfferValidator test_valid;
	ServiceOffer test_serv(test_repo, test_valid);
	string denum = "Familie";
	string dest = "Kiev";
	string type = "Roadtrip";
	double price = 69;
	test_serv.addServiceOffer(denum, dest, type, price);
	const auto& offers = test_serv.getAllService();
	assert(offers.getSize() == 1);
}

void testDeleteOfferService() {
	RepoOffer test_repo;
	OfferValidator test_valid;
	ServiceOffer test_serv(test_repo, test_valid);
	string denum = "Familie";
	string dest = "Kiev";
	string type = "Roadtrip";
	double price = 69;
	test_serv.addServiceOffer(denum, dest, type, price);
	const auto& offers = test_serv.getAllService();
	assert(offers.getSize() == 1);
	test_serv.deleteServiceOffer(0);
	const auto& offers2 = test_serv.getAllService();
	assert(offers2.getSize() == 0);
}

void testModifyOfferService() {
	RepoOffer test_repo;
	OfferValidator test_valid;
	ServiceOffer test_serv(test_repo, test_valid);
	string denum = "Familie";
	string dest = "Kiev";
	string type = "Roadtrip";
	double price = 69;
	test_serv.addServiceOffer(denum, dest, type, price);
	const auto& offers = test_serv.getAllService();
	assert(offers.getSize() == 1);
	string new_denum = "Business";
	string new_dest = "Odesa";
	string new_type = "Tren";
	double new_price = 169;
	test_serv.modifyServiceOffer(0, new_denum, new_dest, new_type, new_price);
	const auto& offers2 = test_serv.getAllService();
	assert(offers2.getSize() == 1);
	assert(offers2.getElem(0).getDenumire() == "Business");
	assert(offers2.getElem(0).getDestinatie() == "Odesa");
	assert(offers2.getElem(0).getType() == "Tren");
	assert(offers2.getElem(0).getPrice() == 169);
}

void testFindOfferService() {
	RepoOffer test_repo;
	OfferValidator test_valid;
	ServiceOffer test_serv(test_repo, test_valid);
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
	assert(offers.getSize() == 2);
	const auto& found = test_serv.findOfferService(1);
	assert(found.getDenumire() == "Business");
	assert(found.getDestinatie() == "Odesa");
	assert(found.getType() == "Tren");
	assert(found.getPrice() == 169);
}

/*void testFilterPrice() {
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
	assert(offers.getSize() == 2);
	const auto& filtered = test_serv.filter_price(169);
	assert(filtered.getSize() == 1);
	assert(filtered.getElem(0).getDenumire() == "Business");
	assert(filtered.getElem(0).getDestinatie() == "Odesa");
	assert(filtered.getElem(0).getType() == "Tren");
	assert(filtered.getElem(0).getPrice() == 169);
}*/

void testFilters() {
	RepoOffer test_repo;
	OfferValidator test_valid;
	ServiceOffer test_serv(test_repo, test_valid);
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
	assert(offers.getSize() == 2);
	const auto& fct = test_serv.filtrare_pret(169);
	assert(fct.getSize() == 1);
	assert(fct.getElem(0).getDenumire() == "Business");
	assert(fct.getElem(0).getDestinatie() == "Odesa");
	assert(fct.getElem(0).getType() == "Tren");
	assert(fct.getElem(0).getPrice() == 169);
	const auto& fct2 = test_serv.filtrare_dest("Kiev");
	assert(fct2.getSize() == 1);
	assert(fct2.getElem(0).getDenumire() == "Familie");
	assert(fct2.getElem(0).getDestinatie() == "Kiev");
	assert(fct2.getElem(0).getType() == "Roadtrip");
	assert(fct2.getElem(0).getPrice() == 69);
}

void testSorts() {
	RepoOffer test_repo;
	OfferValidator test_valid;
	ServiceOffer test_serv(test_repo, test_valid);
	string denum = "Familie";
	string dest = "Kiev";
	string type = "Woadtrip";
	double price = 69;
	test_serv.addServiceOffer(denum, dest, type, price);
	string denum2 = "Business";
	string dest2 = "Odesa";
	string type2 = "Tren";
	double price2 = 169;
	test_serv.addServiceOffer(denum2, dest2, type2, price2);
	const auto& sorted = test_serv.sortDenumire();
	assert(sorted.getElem(0).getDenumire() == "Business");
	assert(sorted.getElem(0).getDestinatie() == "Odesa");
	assert(sorted.getElem(0).getType() == "Tren");
	assert(sorted.getElem(0).getPrice() == 169);
	const auto& sorted2 = test_serv.sortDest();
	assert(sorted2.getElem(0).getDenumire() == "Familie");
	assert(sorted2.getElem(0).getDestinatie() == "Kiev");
	assert(sorted2.getElem(0).getType() == "Woadtrip");
	assert(sorted2.getElem(0).getPrice() == 69);
	const auto& sorted3 = test_serv.sortFinal();
	assert(sorted3.getElem(0).getDenumire() == "Familie");
}