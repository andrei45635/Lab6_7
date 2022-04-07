#include "offer_repo.h"
//#include "VectDinamic.h"
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
	offers.add(ofr);
}

const VectDinamic<Offer>& RepoOffer::getAll() {
	return offers;
}

void RepoOffer::deleteRepoOffer(int pos) {
	if (pos > offers.getSize()) {
		throw RepoException("Oferta nu exista!\n");
	}
	for (int i = 0; i < offers.getSize(); i++) {
		if (pos == i) {
			offers.delete_elem(pos);
		}
	}
}

void RepoOffer::modifyRepoOffer(int pos, const Offer& new_ofr) {
	if (pos > offers.getSize()) {
		throw RepoException("Oferta nu exista!\n");
	}
	for (int i = 0; i < offers.getSize(); i++) {
		if (pos == i) {
			//offers.erase(offers.begin() + pos);
			offers.set(pos, new_ofr);
		}
	}
}

Offer RepoOffer::findOfferRepo(int pos) {
	return offers.getElem(pos);
}

void test_create_repo() {
	RepoOffer repots;
	Offer ofr1{ "Vacanta", "Kiev", "Familie", 19 };
	Offer ofr2{ "Croaziera", "Marea Azov", "Familie", 21 };
	repots.addRepoOffer(ofr1);
	repots.addRepoOffer(ofr2);
	const auto& offers = repots.getAll();
	assert(offers.getSize() == 2);
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
	assert(offers.getSize() == 2);
	test_repo.deleteRepoOffer(1);
	assert(offers.getSize() == 1);
	try {
		test_repo.deleteRepoOffer(3);
		assert(false);
	}
	catch (RepoException&) {
		assert(true);
	}
}

void test_modify_repo() {
	RepoOffer test_repo;
	Offer ofr1{ "Vacanta", "Kiev", "Familie", 19 };
	Offer ofr2{ "Croaziera", "Marea Azov", "Familie", 21 };
	Offer ofr3{ "Business", "Odesa", "Tren", 420 };
	test_repo.addRepoOffer(ofr1);
	test_repo.addRepoOffer(ofr2);
	const auto& offers = test_repo.getAll();
	assert(offers.getSize() == 2);
	test_repo.modifyRepoOffer(1, ofr3);
	assert(offers.getSize() == 2);
	assert(ofr3.getDenumire() == offers.getElem(1).getDenumire());
	assert(ofr3.getDestinatie() == offers.getElem(1).getDestinatie());
	assert(ofr3.getType() == offers.getElem(1).getType());
	assert(ofr3.getPrice() == offers.getElem(1).getPrice());
	try {
		test_repo.modifyRepoOffer(3, ofr3);
		assert(false);
	}
	catch (RepoException&) {
		assert(true);
	}
}

void test_find_repo() {
	RepoOffer test_repo;
	Offer ofr1{ "Vacanta", "Kiev", "Familie", 19 };
	Offer ofr2{ "Croaziera", "Marea Azov", "Familie", 21 };
	Offer ofr3{ "Business", "Odesa", "Tren", 420 };
	test_repo.addRepoOffer(ofr1);
	test_repo.addRepoOffer(ofr2);
	const auto& offers = test_repo.getAll();
	assert(offers.getSize() == 2);
	const auto& found  = test_repo.findOfferRepo(1);
	assert(found.getDenumire() == ofr2.getDenumire());
	assert(found.getDestinatie() == ofr2.getDestinatie());
	assert(found.getType() == ofr2.getType());
	assert(found.getPrice() == ofr2.getPrice());
}