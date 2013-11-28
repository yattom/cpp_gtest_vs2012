#include "stdafx.h"

#include "gtest/gtest.h"

#include "fizzbuzz.h"

TEST(FizzBuzz, その他の数のときはその数を返す_中間の場合) {
	ASSERT_STREQ("4", fizzbuzz(4));
}

TEST(FizzBuzz, その他の数のときはその数を返す_最小の場合) {
	const char* result = fizzbuzz(1);
	ASSERT_STREQ("1", result);
}

TEST(FizzBuzz, 3の倍数の時はFizzと返す_3の場合) {
	const char* result = fizzbuzz(3);
	ASSERT_STREQ("Fizz", result);
}

TEST(FizzBuzz, 3の倍数の時はFizzと返す_6の場合) {
	const char* result = fizzbuzz(6);
	ASSERT_STREQ("Fizz", result);
}

TEST(FizzBuzz, 5の倍数の時はBuzzと返す_5の場合) {
	const char* result = fizzbuzz(5);
	ASSERT_STREQ("Buzz", result);
}

TEST(FizzBuzz, 5の倍数の時はBuzzと返す_最大値の場合) {
	const char* result = fizzbuzz(100);
	ASSERT_STREQ("Buzz", result);
}


TEST(FizzBuzz, 3と5の倍数の時はFizzBuzzと返す_15の場合) {
	const char* result = fizzbuzz(15);
	ASSERT_STREQ("FizzBuzz", result);
}
