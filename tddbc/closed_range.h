
#pragma once
class ClosedRange{
public:
	ClosedRange(int lower, int upper);
	int getLower();
	int getUpper();

private:
	int m_lower;
	int m_upper;
};