#pragma once

#include <exception>

class ClosedRange {
private:
	const int lower_endpoint;
	const int upper_endpoint;
public:
	ClosedRange(int lower_endpoint, int upper_endpoint);
	int getLowerEndpoint() const;
	int getUpperEndpoint() const;
};

class RangeException : std::exception {

};