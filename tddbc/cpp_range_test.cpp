#include "stdafx.h"

#include "gtest/gtest.h"

#include "cpp_range.h"

TEST(��Ԃ��쐬�ł���, ���ʂɍ쐬�ł���) {
	ClosedRange range = ClosedRange(3, 8);
	ASSERT_EQ(3, range.getLowerEndpoint());
	ASSERT_EQ(8, range.getUpperEndpoint());
}