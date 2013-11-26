#include "stdafx.h"

#include "gtest/gtest.h"

#include "cpp_range.h"

TEST(閉区間を作成できる, 普通に作成できる) {
	ClosedRange range = ClosedRange(3, 8);
	ASSERT_EQ(3, range.getLowerEndpoint());
	ASSERT_EQ(8, range.getUpperEndpoint());
}
 
TEST(閉区間を作成できる, 上下が逆だとエラー) {
	ASSERT_THROW(ClosedRange(8, 3), RangeException);
}

TEST(閉区間を作成できる, 上下が同じならOK) {
	ClosedRange range = ClosedRange(3, 3);
	ASSERT_EQ(3, range.getLowerEndpoint());
	ASSERT_EQ(3, range.getUpperEndpoint());
}

TEST(閉区間に点が含まれる, 含まれる場合) {
	ClosedRange range = ClosedRange(3, 8);
	ASSERT_TRUE(range.contains(5));
}

TEST(閉区間に点が含まれる, 含まれない場合) {
	ClosedRange range = ClosedRange(3, 8);
	ASSERT_FALSE(range.contains(-1));
	ASSERT_FALSE(range.contains(10));
}

TEST(閉区間に点が含まれる, 端点上の場合) {
	ClosedRange range = ClosedRange(3, 8);
	ASSERT_TRUE(range.contains(3));
	ASSERT_TRUE(range.contains(8));
}