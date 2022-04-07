#include "validator.h"
#include <cmath>
#include <iostream>
#include <algorithm>

void OfferValidator::validate_offer(const Offer& ofr) {

	VectDinamic<std::string> errs;
	if (ofr.getDenumire().empty() || ofr.getDenumire() == "0") {
		errs.add("denumirea nu poate fi vida!\n");
	}
	if (ofr.getDestinatie().empty() || ofr.getDestinatie() == "0") {
		errs.add("destinatia nu poate fi vida!\n");
	}
	if (ofr.getType().empty() || ofr.getType() == "0") {
		errs.add("tipul nu poate fi vid!\n");
	}
	if (fabs(ofr.getPrice() < 0.00001)) {
		errs.add("pretul nu poate fi negativ!\n");
	}
	if (errs.getSize() != 0) {
		throw ValidException(errs);
	}
}