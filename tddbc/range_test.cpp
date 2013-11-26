#include "stdafx.h"
#include "gtest/gtest.h"

#include "range.h"

TEST(閉区間に含まれるか, 中間の場合) {
	closed_range r = create_closed_range(3, 8);
	ASSERT_TRUE(contained_in_closed_range(r, 5));
}

TEST(閉区間に含まれるか, 開始点の場合) {
	closed_range r = create_closed_range(3, 8);
	ASSERT_TRUE(contained_in_closed_range(r, 3));
}

TEST(閉区間に含まれるか, 終了点の場合) {
	closed_range r = create_closed_range(3, 8);
	ASSERT_TRUE(contained_in_closed_range(r, 8));
}

TEST(閉区間に含まれるか, 小さすぎる場合) {
	closed_range r = create_closed_range(3, 8);
	ASSERT_FALSE(contained_in_closed_range(r, 2));
}

TEST(閉区間に含まれるか, 大きすぎる場合) {
	closed_range r = create_closed_range(3, 8);
	ASSERT_FALSE(contained_in_closed_range(r, 9));
}

TEST(閉区間を文字列にする, 通常) {
	char buf[20];
	closed_range r = create_closed_range(3, 8);
	ASSERT_STREQ("[3,8]", closed_range_to_str(r, buf, sizeof(buf)));
}

TEST(閉区間を文字列にする, 逆転でエラー) {
	char buf[20];
	closed_range r = create_closed_range(8, 3);
	ASSERT_EQ(NULL, closed_range_to_str(r, buf, sizeof(buf)));
}

TEST(閉区間を文字列にする, 開始終了が一致してもよい) {
	char buf[20];
	closed_range r = create_closed_range(5, 5);
	ASSERT_STREQ("[5,5]", closed_range_to_str(r, buf, sizeof(buf)));
}

TEST(閉区間が等しいか, 等しい場合) {
	closed_range r1 = create_closed_range(3, 8);
	closed_range r2 = create_closed_range(3, 8);
	ASSERT_TRUE(closed_range_equal(r1, r2));
}

TEST(閉区間が等しいか, 等しくない場合) {
	closed_range r1 = create_closed_range(3, 8);
	closed_range r2 = create_closed_range(3, 7);
	ASSERT_FALSE(closed_range_equal(r1, r2));
}

TEST(閉区間の接続, 離れている場合) {
	closed_range r1 = create_closed_range(3, 8);
	closed_range r2 = create_closed_range(9, 15);
	ASSERT_FALSE(closed_range_connected(r1, r2));
}

TEST(閉区間の接続, range1の終了点とrange2の開始点が接する場合) {
	closed_range r1 = create_closed_range(3, 8);
	closed_range r2 = create_closed_range(8, 15);
	ASSERT_TRUE(closed_range_connected(r1, r2));
}

TEST(閉区間の接続, range2の終了点とrange1の開始点が接する場合) {
	closed_range r1 = create_closed_range(15, 20);
	closed_range r2 = create_closed_range(8, 15);
	ASSERT_TRUE(closed_range_connected(r1, r2));
}

TEST(開区間に含まれるか, 中間の場合) {
	open_range r = create_open_range(3, 8);
	ASSERT_TRUE(contained_in_open_range(r, 5));
}

TEST(開区間に含まれるか, 開始点の場合) {
	open_range r = create_open_range(3, 8);
	ASSERT_FALSE(contained_in_open_range(r, 3));
}

TEST(開区間に含まれるか, 終了点の場合) {
	open_range r = create_open_range(3, 8);
	ASSERT_FALSE(contained_in_open_range(r, 8));
}

TEST(開区間を文字列にする, 通常) {
	char buf[20];
	open_range r = create_open_range(3, 8);
	ASSERT_STREQ("(3,8)", open_range_to_str(r, buf, sizeof(buf)));
}

TEST(開区間を文字列にする, 開始終了が一致したらエラー) {
	char buf[20];
	open_range r = create_open_range(5, 5);
	ASSERT_EQ(NULL, open_range_to_str(r, buf, sizeof(buf)));
}


TEST(開区間が等しいか, 等しい場合) {
	open_range r1 = create_open_range(3, 8);
	open_range r2 = create_open_range(3, 8);
	ASSERT_TRUE(open_range_equal(r1, r2));
}

TEST(開区間が等しいか, 等しくない場合) {
	open_range r1 = create_open_range(3, 8);
	open_range r2 = create_open_range(3, 7);
	ASSERT_FALSE(open_range_equal(r1, r2));
}

TEST(開区間の接続, 離れている場合) {
	open_range r1 = create_open_range(3, 8);
	open_range r2 = create_open_range(9, 15);
	ASSERT_FALSE(open_range_connected(r1, r2));
}

TEST(開区間の接続, range1の終了点とrange2の開始点が接する場合) {
	open_range r1 = create_open_range(3, 8);
	open_range r2 = create_open_range(7, 15);
	ASSERT_TRUE(open_range_connected(r1, r2));
}

TEST(開区間の接続, range2の終了点とrange1の開始点が接する場合) {
	open_range r1 = create_open_range(15, 20);
	open_range r2 = create_open_range(8, 16);
	ASSERT_TRUE(open_range_connected(r1, r2));
}

TEST(閉区間の共通集合, 同じ区間の場合) {
	char buf[20];
	closed_range r = create_closed_range(3, 8);
	closed_range result;
	closed_range* actual = intersection_of_closed_ranges(r, r, &result);
	ASSERT_STREQ("[3,8]", closed_range_to_str(*actual, buf, sizeof(buf)));
}

TEST(閉区間の共通集合, 一部重なる場合_1番目が下) {
	char buf[20];
	closed_range r1 = create_closed_range(3, 8);
	closed_range r2 = create_closed_range(5, 12);
	closed_range result;
	closed_range* actual = intersection_of_closed_ranges(r1, r2, &result);
	ASSERT_STREQ("[5,8]", closed_range_to_str(*actual, buf, sizeof(buf)));
}

TEST(閉区間の共通集合, 一部重なる場合_2番目が下) {
	char buf[20];
	closed_range r1 = create_closed_range(5, 12);
	closed_range r2 = create_closed_range(3, 8);
	closed_range result;
	closed_range* actual = intersection_of_closed_ranges(r1, r2, &result);
	ASSERT_STREQ("[5,8]", closed_range_to_str(*actual, buf, sizeof(buf)));
}

TEST(閉区間の共通集合, 片方が包含される場合) {
	char buf[20];
	closed_range r1 = create_closed_range(1, 12);
	closed_range r2 = create_closed_range(3, 8);
	closed_range result;
	closed_range* actual = intersection_of_closed_ranges(r1, r2, &result);
	ASSERT_STREQ("[3,8]", closed_range_to_str(*actual, buf, sizeof(buf)));
}

TEST(閉区間の共通集合, 重ならない場合) {
	char buf[20];
	closed_range r1 = create_closed_range(3, 8);
	closed_range r2 = create_closed_range(10, 15);
	closed_range result;
	closed_range* actual = intersection_of_closed_ranges(r1, r2, &result);
	ASSERT_EQ(NULL, actual);
}