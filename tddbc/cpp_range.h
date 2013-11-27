#pragma once

#include <exception>

class ClosedRange {
public:
	const int lower_endpoint;
	const int upper_endpoint;

	ClosedRange(int lower_endpoint, int upper_endpoint);
	int contains(int point) const;
	operator std::string() const;
};

class RangeException : std::exception {

};