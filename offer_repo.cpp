#include "offer_repo.h"
#include <assert.h>
#include <iostream>

using std::cout;

string RepoException::getMessage() {
	return mesg;
}

void RepoOffer::addRepoOffer(const Offer& ofr) {
	for (const Offer& oferta : offers) {
		if (oferta.getDenumire() == ofr.getDenumire() && oferta.getDestinatie() == ofr.getDestinatie() && oferta.getType() == ofr.getType())
			throw RepoException("Oferta exista!\n");
	}
	offers.push_back(ofr);
}

const vector<Offer>& RepoOffer::getAll() {
	return offers;
}

void RepoOffer::deleteRepoOffer(int pos) {
	for (int i = 0; i < offers.size(); i++) {
		if (pos == i) {
			offers.erase(offers.begin()+pos);
		}
	}
}

void RepoOffer::modifyRepoOffer(int pos, const Offer& new_ofr) {
	for (int i = 0; i < offers.size(); i++) {
		if (pos == i) {
			offers.erase(offers.begin() + pos);
			offers.insert(offers.begin() + pos, new_ofr);
		}
	}
}

Offer RepoOffer::findOfferRepo(int pos) {
	return offers[pos];
}

void test_create_repo() {
	RepoOffer repots;
	Offer ofr1{ "Vacanta", "Kiev", "Familie", 19 };
	Offer ofr2{ "Croaziera", "Marea Azov", "Familie", 21 };
	repots.addRepoOffer(ofr1);
	repots.addRepoOffer(ofr2);
	const auto& offers = repots.getAll();
	assert(offers.size() == 2);
	try {
		repots.addRepoOffer(ofr1);
		assert(false);
	}
	catch (RepoException&) {
		assert(true);
	}
}

void test_delete_repo() {
	RepoOffer test_repo;
	Offer ofr1{ "Vacanta", "Kiev", "Familie", 19 };
	Offer ofr2{ "Croaziera", "Marea Azov", "Familie", 21 };
	test_repo.addRepoOffer(ofr1);
	test_repo.addRepoOffer(ofr2);
	const auto& offers = test_repo.getAll();
	assert(offers.size() == 2);
	test_repo.deleteRepoOffer(1);
	assert(offers.size() == 1);
}

void test_modify_repo() {
	RepoOffer test_repo;
	Offer ofr1{ "Vacanta", "Kiev", "Familie", 19 };
	Offer ofr2{ "Croaziera", "Marea Azov", "Familie", 21 };
	Offer ofr3{ "Business", "Odesa", "Tren", 420 };
	test_repo.addRepoOffer(ofr1);
	test_repo.addRepoOffer(ofr2);
	const auto& offers = test_repo.getAll();
	assert(offers.size() == 2);
	test_repo.modifyRepoOffer(1, ofr3);
	assert(offers.size() == 2);
	assert(ofr3.getDenumire() == offers[1].getDenumire());
	assert(ofr3.getDestinatie() == offers[1].getDestinatie());
	assert(ofr3.getType() == offers[1].getType());
	assert(ofr3.getPrice() == offers[1].getPrice());
}

void test_find_repo() {
	RepoOffer test_repo;
	Offer ofr1{ "Vacanta", "Kiev", "Familie", 19 };
	Offer ofr2{ "Croaziera", "Marea Azov", "Familie", 21 };
	Offer ofr3{ "Business", "Odesa", "Tren", 420 };
	test_repo.addRepoOffer(ofr1);
	test_repo.addRepoOffer(ofr2);
	const auto& offers = test_repo.getAll();
	assert(offers.size() == 2);
	const auto& found  = test_repo.findOfferRepo(1);
	assert(found.getDenumire() == ofr2.getDenumire());
	assert(found.getDestinatie() == ofr2.getDestinatie());
	assert(found.getType() == ofr2.getType());
	assert(found.getPrice() == ofr2.getPrice());
}