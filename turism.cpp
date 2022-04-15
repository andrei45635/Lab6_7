#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include "oferta.h"
#include "offer_repo.h"
#include "offer_service.h"
#include "UI.h"

void runAllTests() {
	std::cout << "beginning testing..." << std::endl;
	testCreateOffer();
	test_create_repo();
	test_delete_repo();
	test_modify_repo();
	test_find_repo();
	testCreateService();
	testDeleteOfferService();
	testModifyOfferService();
	testFindOfferService();
	//testFilterPrice();
	testFilters();
	testSorts();
	testAddCart();
	testDeleteFromCart();
	testGenerateRandom();
	testAddToWish();
	testDeleteWish();
	testGenerateWish();
	std::cout << "finished testing..." << std::endl;
}

int main() {
	runAllTests();
	OfferValidator valid;
	RepoOffer repo;
	Wishlist wish;
	ServiceOffer serv(repo, valid, wish);
	UI ui(serv);
	ui.startUI();
	_CrtDumpMemoryLeaks();
	return 0;
}