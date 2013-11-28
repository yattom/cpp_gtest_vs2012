#include "stdafx.h"

#include "gtest/gtest.h"
#include "closed_range.h"

TEST(コンストラクタの引数は下端点と上端点の順で値を取る, コンストラクタの引数は下端点が３と上端点は８を取る)
{
	ClosedRange cr = ClosedRange(3, 8);
}

TEST(下端点を取得する, 下端点が３である)
{
	ClosedRange cr = ClosedRange(3, 8);

	ASSERT_EQ(3, cr.getLower());
}


TEST(上端点を取得する, 上端点が８である)
{
	ClosedRange cr = ClosedRange(3, 8);

	ASSERT_EQ(8, cr.getUpper());
}


TEST(コンストラクタの引数, 下端点＜上端点)
{
	ASSERT_NO_THROW(ClosedRange(3, 8));
}

TEST(コンストラクタの引数, 下端点＞上端点)
{
	ASSERT_ANY_THROW(ClosedRange(8, 3));
}

TEST(コンストラクタの引数, 下端点＝上端点)
{
	ASSERT_NO_THROW(ClosedRange(3, 3));
}
