#include "stdafx.h"

#include <stdlib.h>
#include <stdio.h>
#include "range.h"

closed_range create_closed_range(int lower_endpoint, int upper_endpoint)
{
	closed_range created = {lower_endpoint, upper_endpoint};
	return created;
}

int contained_in_closed_range(int lower_endpoint, int upper_endpoint, int subject)
{
	return lower_endpoint <= subject && subject <= upper_endpoint;
}

const char* closed_range_to_str(int lower_endpoint, int upper_endpoint, char* buf)
{
	if(lower_endpoint > upper_endpoint)
	{
		return NULL;
	}
	sprintf(buf, "(%d,%d)", lower_endpoint, upper_endpoint);
	return buf;
}

int closed_range_equal(int lower_endpoint_1, int upper_endpoint_1, int lower_endpoint_2, int upper_endpoint_2)
{
	return lower_endpoint_1 == lower_endpoint_2 && upper_endpoint_1 == upper_endpoint_2;
}

int closed_range_equal(closed_range range1, closed_range range2)
{
	return closed_range_equal(range1.lower_endpoint, range1.upper_endpoint, range2.lower_endpoint, range2.upper_endpoint);
}