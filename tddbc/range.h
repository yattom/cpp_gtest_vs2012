#ifndef __RANGE_H__
#define __RANGE_H__

const char* closed_range_to_str(int lower_endpoint, int upper_endpoint, char* buf);
int contained_in_closed_range(int lower_endpoint, int upper_endpoint, int subject);

#endif