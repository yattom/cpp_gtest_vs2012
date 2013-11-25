#include "stdafx.h"

#include <stdlib.h>
#include <stdio.h>
#include "range.h"

closed_range create_closed_range(int lower_endpoint, int upper_endpoint)
{
	closed_range created = {lower_endpoint, upper_endpoint};
	return created;
}

int contained_in_closed_range(closed_range r, int subject)
{
	return r.lower_endpoint <= subject && subject <= r.upper_endpoint;
}

const char* closed_range_to_str(closed_range r, char* buf)
{
	if(r.lower_endpoint > r.upper_endpoint)
	{
		return NULL;
	}
	sprintf(buf, "(%d,%d)", r.lower_endpoint, r.upper_endpoint);
	return buf;
}

int closed_range_equal(closed_range r1, closed_range r2)
{
	return r1.lower_endpoint == r2.lower_endpoint && r1.upper_endpoint == r2.upper_endpoint;
}

int closed_range_connected(closed_range r1, closed_range r2) {
	if(r1.upper_endpoint == r2.lower_endpoint || r2.upper_endpoint == r1.lower_endpoint) {
		return 1;
	}
	return 0;
}