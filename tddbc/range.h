#ifndef __RANGE_H__
#define __RANGE_H__

typedef struct _closed_range {
	int lower_endpoint;
	int upper_endpoint;
} closed_range;

closed_range create_closed_range(int lower_endpoint, int upper_endpoint);
const char* closed_range_to_str(closed_range range, char* buf);
int contained_in_closed_range(closed_range range, int subject);
int closed_range_equal(closed_range range1, closed_range range2);

#endif