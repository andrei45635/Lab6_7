#pragma once
#include <string>
#include "oferta.h"
//#include "VectDinamic.h"
#include <vector>

using std::vector;

class ValidException {
private:
	vector<std::string> exceptions;
public:
	//constructor pentru validator
	ValidException(vector<std::string> exceptions): exceptions{exceptions}{}
	//getter pentru validator
	const vector<std::string>& get_error() const { return this->exceptions; }
};

class OfferValidator {
public:
	void validate_offer(const Offer& ofr);
};