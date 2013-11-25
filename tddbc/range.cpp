#include "stdafx.h"

#include "range.h"

int contained_in_closed_range(int lower_endpoint, int upper_endpoint, int subject)
{
	return lower_endpoint <= subject && subject <= upper_endpoint;
}
