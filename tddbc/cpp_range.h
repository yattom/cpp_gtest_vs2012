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
	int contains(int point) const;
	operator std::string() const;
};

class RangeException : std::exception {

};