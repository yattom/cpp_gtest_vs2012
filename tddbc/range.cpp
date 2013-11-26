#include "stdafx.h"

#include <stdlib.h>
#include <stdio.h>
#include "range.h"

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

closed_range create_closed_range(int lower_endpoint, int upper_endpoint)
{
	closed_range created = {lower_endpoint, upper_endpoint};
	return created;
}

int contained_in_closed_range(closed_range r, int point)
{
	return r.lower_endpoint <= point && point <= r.upper_endpoint;
}

const char* closed_range_to_str(closed_range r, char* buf, size_t bufsize)
{
	if(r.lower_endpoint > r.upper_endpoint)
	{
		return NULL;
	}
	_snprintf(buf, bufsize, "[%d,%d]", r.lower_endpoint, r.upper_endpoint);
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

open_range create_open_range(int lower_endpoint, int upper_endpoint)
{
	open_range created = {lower_endpoint, upper_endpoint};
	return created;
}

int contained_in_open_range(open_range r, int point)
{
	return r.lower_endpoint < point && point < r.upper_endpoint;
}

const char* open_range_to_str(open_range r, char* buf, size_t bufsize)
{
	if(r.lower_endpoint >= r.upper_endpoint)
	{
		return NULL;
	}
	_snprintf(buf, bufsize, "(%d,%d)", r.lower_endpoint, r.upper_endpoint);
	return buf;
}

int open_range_equal(open_range r1, open_range r2)
{
	return r1.lower_endpoint == r2.lower_endpoint && r1.upper_endpoint == r2.upper_endpoint;
}

int open_range_connected(open_range r1, open_range r2) {
	if(r1.upper_endpoint - 1 == r2.lower_endpoint || r2.upper_endpoint - 1 == r1.lower_endpoint) {
		return 1;
	}
	return 0;
}

closed_range* intersection_of_closed_ranges(closed_range r1, closed_range r2, closed_range* out) {
	if(r1.upper_endpoint < r2.lower_endpoint || r2.upper_endpoint < r1.lower_endpoint) {
		return NULL;
	}
	out->lower_endpoint = max(r1.lower_endpoint, r2.lower_endpoint);
	out->upper_endpoint = min(r1.upper_endpoint, r2.upper_endpoint);
	return out;
}