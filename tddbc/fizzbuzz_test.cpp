#include "stdafx.h"

#include "gtest/gtest.h"

#include "fizzbuzz.h"

TEST(FizzBuzz, ���̑��̐��̂Ƃ��͂��̐���Ԃ�_���Ԃ̏ꍇ) {
	ASSERT_STREQ("4", fizzbuzz(4));
}

TEST(FizzBuzz, ���̑��̐��̂Ƃ��͂��̐���Ԃ�_�ŏ��̏ꍇ) {
	const char* result = fizzbuzz(1);
	ASSERT_STREQ("1", result);
}

TEST(FizzBuzz, 3�̔{���̎���Fizz�ƕԂ�_3�̏ꍇ) {
	const char* result = fizzbuzz(3);
	ASSERT_STREQ("Fizz", result);
}

TEST(FizzBuzz, 3�̔{���̎���Fizz�ƕԂ�_6�̏ꍇ) {
	const char* result = fizzbuzz(6);
	ASSERT_STREQ("Fizz", result);
}

TEST(FizzBuzz, 5�̔{���̎���Buzz�ƕԂ�_5�̏ꍇ) {
	const char* result = fizzbuzz(5);
	ASSERT_STREQ("Buzz", result);
}

TEST(FizzBuzz, 5�̔{���̎���Buzz�ƕԂ�_�ő�l�̏ꍇ) {
	const char* result = fizzbuzz(100);
	ASSERT_STREQ("Buzz", result);
}


TEST(FizzBuzz, 3��5�̔{���̎���FizzBuzz�ƕԂ�_15�̏ꍇ) {
	const char* result = fizzbuzz(15);
	ASSERT_STREQ("FizzBuzz", result);
}
