#include "stdafx.h"
#include "gtest/gtest.h"

#include "range.h"

TEST(閉区間に含まれるか, 中間の場合) {
	ASSERT_TRUE(contained_in_closed_range(3, 8, 5));
}