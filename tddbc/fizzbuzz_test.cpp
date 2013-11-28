#include "stdafx.h"

#include "gtest/gtest.h"

#include "fizzbuzz.h"

TEST(FizzBuzz, ‚»‚Ì‘¼‚Ì”‚Ì‚Æ‚«‚Í‚»‚Ì”‚ğ•Ô‚·_’†ŠÔ‚Ìê‡) {
	ASSERT_STREQ("4", fizzbuzz(4));
}

TEST(FizzBuzz, ‚»‚Ì‘¼‚Ì”‚Ì‚Æ‚«‚Í‚»‚Ì”‚ğ•Ô‚·_Å¬‚Ìê‡) {
	const char* result = fizzbuzz(1);
	ASSERT_STREQ("1", result);
}

TEST(FizzBuzz, 3‚Ì”{”‚Ì‚ÍFizz‚Æ•Ô‚·_3‚Ìê‡) {
	const char* result = fizzbuzz(3);
	ASSERT_STREQ("Fizz", result);
}

TEST(FizzBuzz, 3‚Ì”{”‚Ì‚ÍFizz‚Æ•Ô‚·_6‚Ìê‡) {
	const char* result = fizzbuzz(6);
	ASSERT_STREQ("Fizz", result);
}

TEST(FizzBuzz, 5‚Ì”{”‚Ì‚ÍBuzz‚Æ•Ô‚·_5‚Ìê‡) {
	const char* result = fizzbuzz(5);
	ASSERT_STREQ("Buzz", result);
}

TEST(FizzBuzz, 5‚Ì”{”‚Ì‚ÍBuzz‚Æ•Ô‚·_Å‘å’l‚Ìê‡) {
	const char* result = fizzbuzz(100);
	ASSERT_STREQ("Buzz", result);
}


TEST(FizzBuzz, 3‚Æ5‚Ì”{”‚Ì‚ÍFizzBuzz‚Æ•Ô‚·_15‚Ìê‡) {
	const char* result = fizzbuzz(15);
	ASSERT_STREQ("FizzBuzz", result);
}
