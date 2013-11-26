#pragma once

class ClosedRange {
private:
	int lower_endpoint;
	int upper_endpoint;
public:
	ClosedRange(int lower_endpoint, int upper_endpoint);
	int getLowerEndpoint() const;
	int getUpperEndpoint() const;
};
