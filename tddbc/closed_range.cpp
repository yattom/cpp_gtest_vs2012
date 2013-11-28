#include "stdafx.h"
#include "closed_range.h"

ClosedRange::ClosedRange(int lower, int upper)
	:m_lower(lower),
	 m_upper(upper)
{
	if (m_upper < m_lower) {
		throw(0);
	}
}

int ClosedRange::getLower() const{
	return (m_lower);
}

int ClosedRange::getUpper() const{
	return (m_upper);
}

bool ClosedRange::contains(int n) {
	if (n <= m_upper && n >= m_lower) {
		return (true);
	} else {
		return (false);
	}
}

bool ClosedRange::equals(const ClosedRange &cr_b){

	if (m_lower == cr_b.getLower() &&
		m_upper == cr_b.getUpper()) {
		return(true);
	} else {
		return(false);
	}
}

bool ClosedRange::isConnectedTo(const ClosedRange &cr_b) {

	if (m_lower > cr_b.getUpper()) {
		return (false);
	}

	if (m_upper < cr_b.getLower()) {
		return (false);
	}

	return (true);
}


