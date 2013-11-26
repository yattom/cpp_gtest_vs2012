#include "stdafx.h"

#include "cpp_range.h"

ClosedRange::ClosedRange(int lower_endpoint, int upper_endpoint) {
	this->lower_endpoint = lower_endpoint;
	this->upper_endpoint = upper_endpoint;
}

int ClosedRange::getLowerEndpoint() const {
	return this->lower_endpoint;
}

int ClosedRange::getUpperEndpoint() const {
	return this->upper_endpoint;
}
