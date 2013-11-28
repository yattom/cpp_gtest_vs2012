
#pragma once
class ClosedRange{
public:
	ClosedRange(int lower, int upper);
	int getLower() const;
	int getUpper() const;
	bool contains(int n);
	bool equals(const ClosedRange &cr_b);
	bool isConnectedTo(const ClosedRange &cr_b);
private:
	int m_lower;
	int m_upper;
};