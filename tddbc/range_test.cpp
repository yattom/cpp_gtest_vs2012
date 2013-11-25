#include "stdafx.h"
#include "gtest/gtest.h"

#include "range.h"

TEST(��ԂɊ܂܂�邩, ���Ԃ̏ꍇ) {
	ASSERT_TRUE(contained_in_closed_range(3, 8, 5));
}

TEST(��ԂɊ܂܂�邩, �J�n�_�̏ꍇ) {
	ASSERT_TRUE(contained_in_closed_range(3, 8, 3));
}

TEST(��ԂɊ܂܂�邩, �I���_�̏ꍇ) {
	ASSERT_TRUE(contained_in_closed_range(3, 8, 8));
}

TEST(��ԂɊ܂܂�邩, ����������ꍇ) {
	ASSERT_FALSE(contained_in_closed_range(3, 8, 2));
}

TEST(��ԂɊ܂܂�邩, �傫������ꍇ) {
	ASSERT_FALSE(contained_in_closed_range(3, 8, 9));
}

TEST(��Ԃ𕶎���ɂ���, �ʏ�) {
	char buf[20];
	ASSERT_STREQ("(3,8)", closed_range_to_str(3, 8, buf));
}

TEST(��Ԃ𕶎���ɂ���, �t�]�ŃG���[) {
	char buf[20];
	ASSERT_EQ(NULL, closed_range_to_str(8, 3, buf));
}

TEST(��Ԃ𕶎���ɂ���, �J�n�I������v���Ă��悢) {
	char buf[20];
	ASSERT_STREQ("(5,5)", closed_range_to_str(5, 5, buf));
}

TEST(��Ԃ���������, �������ꍇ) {
	ASSERT_TRUE(closed_range_equal(3, 8, 3, 8));
}

TEST(��Ԃ���������, �������Ȃ��ꍇ) {
	ASSERT_FALSE(closed_range_equal(3, 8, 3, 7));
}

