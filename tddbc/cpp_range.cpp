#include "stdafx.h"

#include <string>
#include "cpp_range.h"

ClosedRange::ClosedRange(int lower_endpoint, int upper_endpoint) 
	: lower_endpoint(lower_endpoint), upper_endpoint(upper_endpoint)  {
	if(lower_endpoint > upper_endpoint) {
		throw RangeException();
	}
}

int ClosedRange::getLowerEndpoint() const {
	return this->lower_endpoint;
}

int ClosedRange::getUpperEndpoint() const {
	return this->upper_endpoint;
}

int ClosedRange::contains(int point) const {
	return lower_endpoint <= point && point <= upper_endpoint;
}

ClosedRange::operator std::string() const {
	char buf[24];
	_snprintf(buf, sizeof(buf), "[%d,%d]", lower_endpoint, upper_endpoint);
	return buf;
}