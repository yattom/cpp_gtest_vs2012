#include "stdafx.h"
#include "closed_range.h"

ClosedRange::ClosedRange(int lower, int upper)
	:m_lower(lower),
	 m_upper(upper)
{
	if(m_upper < m_lower)
		throw(0);
};

int ClosedRange::getLower() {
	return m_lower;
};

int ClosedRange::getUpper() {
	return m_upper;
}
