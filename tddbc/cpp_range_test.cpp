#include "stdafx.h"

#include "gtest/gtest.h"

#include "cpp_range.h"

TEST(��Ԃ��쐬�ł���, ���ʂɍ쐬�ł���) {
	ClosedRange range = ClosedRange(3, 8);
	ASSERT_EQ(3, range.getLowerEndpoint());
	ASSERT_EQ(8, range.getUpperEndpoint());
}
 
TEST(��Ԃ��쐬�ł���, �㉺���t���ƃG���[) {
	ASSERT_THROW(ClosedRange(8, 3), RangeException);
}

TEST(��Ԃ��쐬�ł���, �㉺�������Ȃ�OK) {
	ClosedRange range = ClosedRange(3, 3);
	ASSERT_EQ(3, range.getLowerEndpoint());
	ASSERT_EQ(3, range.getUpperEndpoint());
}
