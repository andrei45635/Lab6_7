#include "validator.h"
#include <cmath>
#include <iostream>
#include <algorithm>

void OfferValidator::validate_offer(const Offer& ofr) {

	vector<std::string> errs;
	if (ofr.getDenumire().empty() || ofr.getDenumire() == "0") {
		errs.push_back("denumirea nu poate fi vida!\n");
	}
	if (ofr.getDestinatie().empty() || ofr.getDestinatie() == "0") {
		errs.push_back("destinatia nu poate fi vida!\n");
	}
	if (ofr.getType().empty() || ofr.getType() == "0") {
		errs.push_back("tipul nu poate fi vid!\n");
	}
	if (fabs(ofr.getPrice() < 0.00001)) {
		errs.push_back("pretul nu poate fi negativ!\n");
	}
	if (errs.size() != 0) {
		throw ValidException(errs);
	}
}