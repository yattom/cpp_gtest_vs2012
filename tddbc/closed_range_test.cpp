#include "stdafx.h"

#include "gtest/gtest.h"
#include "closed_range.h"

TEST(コンストラクタの引数は下端点と上端点の順で値を取る, コンストラクタの引数は下端点が３と上端点は８を取る)
{
	ClosedRange cr = ClosedRange(3, 8);
}

TEST(【閉区間】ゲッター関数, 下端点を３に設定したら３を取得できる)
{
	ClosedRange cr = ClosedRange(3, 8);

	ASSERT_EQ(3, cr.getLower());
}

TEST(【閉区間】ゲッター関数, 上端点を８に設定したら８を取得できる)
{
	ClosedRange cr = ClosedRange(3, 8);

	ASSERT_EQ(8, cr.getUpper());
}

TEST(【閉区間】コンストラクタの引数チェック, 下端点＜上端点の場合はエラーとして例外を投げない)
{
	ASSERT_NO_THROW(ClosedRange(3, 8));
}

TEST(【閉区間】コンストラクタの引数チェック, 下端点＞上端点の場合はエラーとして例外を投げる)
{
	ASSERT_ANY_THROW(ClosedRange(8, 3));
}

TEST(【閉区間】コンストラクタの引数チェック, 下端点＝上端点の場合はエラーとして例外を投げない)
{
	ASSERT_NO_THROW(ClosedRange(3, 3));
}

TEST(【閉区間】区間内外の判定, 3、8のとき5は区間内である)
{
	ClosedRange cr = ClosedRange(3, 8);
	ASSERT_TRUE(cr.contains(5));
}

TEST(【閉区間】区間内外の判定, 3、8のとき9は区間外である)
{
	ClosedRange cr = ClosedRange(3, 8);
	ASSERT_FALSE(cr.contains(9));
}

TEST(【閉区間】区間内外の判定, 3、8のとき2は区間外である)
{
	ClosedRange cr = ClosedRange(3, 8);
	ASSERT_FALSE(cr.contains(2));
}

TEST(【閉区間】区間下端の値, 3、8のとき3は区間内である)
{
	ClosedRange cr = ClosedRange(3, 8);

	ASSERT_TRUE(cr.contains(3));
}

TEST(【閉区間】区間上端の値, 3、8のとき8は区間内である)
{
	ClosedRange cr = ClosedRange(3, 8);

	ASSERT_TRUE(cr.contains(8));
}

TEST(【閉区間】閉区間同士の比較,等しい場合はTrueを返す_3～8と3～8)
{
	ClosedRange cr_a = ClosedRange(3, 8);
	ClosedRange cr_b = ClosedRange(3, 8);

	ASSERT_TRUE(cr_a.equals(cr_b));
}

TEST(【閉区間】閉区間同士の比較,等しくない場合はfalseを返す_3～8と1～6)
{
	ClosedRange cr_a = ClosedRange(3, 8);
	ClosedRange cr_b = ClosedRange(1, 6);

	ASSERT_FALSE(cr_a.equals(cr_b));
}

TEST(【閉区間】閉区間同士の接続,まったく重なっていない場合はFalseを返す_3～8と1～2)
{
	ClosedRange cr_a = ClosedRange(3, 8);
	ClosedRange cr_b = ClosedRange(1, 2);

	ASSERT_FALSE(cr_a.isConnectedTo(cr_b));
}

TEST(【閉区間】閉区間同士の接続,まったく重なっていない場合はFalseを返す_3～8と9～10)
{
	ClosedRange cr_a = ClosedRange(3, 8);
	ClosedRange cr_b = ClosedRange(9, 10);

	ASSERT_FALSE(cr_a.isConnectedTo(cr_b));
}

TEST(【閉区間】閉区間同士の接続,閉区間Aの上限と閉区間Bの下限が一致している場合はTrueを返す)
{
	ClosedRange cr_a = ClosedRange(3, 8);
	ClosedRange cr_b = ClosedRange(8, 10);

	ASSERT_TRUE(cr_a.isConnectedTo(cr_b));
}

TEST(【閉区間】閉区間同士の接続,閉区間Aの下限と閉区間Bの上限が一致している場合はTrueを返す)
{
	ClosedRange cr_a = ClosedRange(3, 8);
	ClosedRange cr_b = ClosedRange(1, 3);

	ASSERT_TRUE(cr_a.isConnectedTo(cr_b));
}


TEST(【閉区間】閉区間同士の接続,閉区間Aの範囲内に閉区間Bが入り込んでいる場合はTrueを返す)
{
	ClosedRange cr_a = ClosedRange(3, 8);
	ClosedRange cr_b = ClosedRange(4, 6);

	ASSERT_TRUE(cr_a.isConnectedTo(cr_b));
}

TEST(【閉区間】閉区間同士の接続,閉区間Aが閉区間Bの範囲内に入り込んでいる場合はTrueを返す)
{
	ClosedRange cr_a = ClosedRange(3, 8);
	ClosedRange cr_b = ClosedRange(1, 10);

	ASSERT_TRUE(cr_a.isConnectedTo(cr_b));
}

