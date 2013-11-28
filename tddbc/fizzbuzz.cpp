#include "stdafx.h"

#include "fizzbuzz.h"

#include <stdlib.h>
#include <stdio.h>

static char buffer[20];

int dividable(int n, int divider) {
	return n % divider == 0;
}

int dividable(int n, int divider1, int divider2) {
	return n % divider1 == 0 && n % divider2 == 0;
}

const char* fizzbuzz(int n) {
	if(dividable(n, 3, 5)) {
		return "FizzBuzz";
	}
	if(dividable(n, 3)) {
		return "Fizz";
	}
	if(dividable(n, 5)) {
		return "Buzz";
	}
	_snprintf(buffer, sizeof(buffer), "%d", n);
	return buffer;
}