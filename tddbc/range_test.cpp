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