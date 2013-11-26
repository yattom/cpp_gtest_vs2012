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

