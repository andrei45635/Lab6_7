#pragma once
#include <string>
#include "oferta.h"
#include "VectDinamic.h"

class ValidException {
private:
	VectDinamic<std::string> exceptions;
public:
	//constructor pentru validator
	ValidException(VectDinamic<std::string> exceptions): exceptions{exceptions}{}
	//getter pentru validator
	const VectDinamic<std::string>& get_error() const { return this->exceptions; }
};

class OfferValidator {
public:
	void validate_offer(const Offer& ofr);
};