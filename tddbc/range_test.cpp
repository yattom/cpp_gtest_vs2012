#include "stdafx.h"
#include "gtest/gtest.h"

#include "range.h"

TEST(閉区間に含まれるか, 中間の場合) {
	ASSERT_TRUE(contained_in_closed_range(3, 8, 5));
}

TEST(閉区間に含まれるか, 開始点の場合) {
	ASSERT_TRUE(contained_in_closed_range(3, 8, 3));
}

TEST(閉区間に含まれるか, 終了点の場合) {
	ASSERT_TRUE(contained_in_closed_range(3, 8, 8));
}

TEST(閉区間に含まれるか, 小さすぎる場合) {
	ASSERT_FALSE(contained_in_closed_range(3, 8, 2));
}

TEST(閉区間に含まれるか, 大きすぎる場合) {
	ASSERT_FALSE(contained_in_closed_range(3, 8, 9));
}

TEST(閉区間を文字列にする, 通常) {
	char buf[20];
	ASSERT_STREQ("(3,8)", closed_range_to_str(3, 8, buf));
}