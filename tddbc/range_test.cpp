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