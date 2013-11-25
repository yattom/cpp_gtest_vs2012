#ifndef __RANGE_H__
#define __RANGE_H__

const char* closed_range_to_str(int lower_endpoint, int upper_endpoint, char* buf);
int contained_in_closed_range(int lower_endpoint, int upper_endpoint, int subject);
int closed_range_equal(int lower_endpoint_1, int upper_endpoint_1, int lower_endpoint_2, int upper_endpoint_2);

#endif