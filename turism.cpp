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
	std::cout << "finished testing..." << std::endl;
}

int main() {
	runAllTests();
	RepoOffer repo;
	ServiceOffer serv(repo);
	UI ui(serv);
	ui.startUI();
	return 0;
}