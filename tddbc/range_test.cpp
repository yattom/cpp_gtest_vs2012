#include "stdafx.h"
#include "gtest/gtest.h"

#include "range.h"

TEST(��ԂɊ܂܂�邩, ���Ԃ̏ꍇ) {
	closed_range r = create_closed_range(3, 8);
	ASSERT_TRUE(contained_in_closed_range(r, 5));
}

TEST(��ԂɊ܂܂�邩, �J�n�_�̏ꍇ) {
	closed_range r = create_closed_range(3, 8);
	ASSERT_TRUE(contained_in_closed_range(r, 3));
}

TEST(��ԂɊ܂܂�邩, �I���_�̏ꍇ) {
	closed_range r = create_closed_range(3, 8);
	ASSERT_TRUE(contained_in_closed_range(r, 8));
}

TEST(��ԂɊ܂܂�邩, ����������ꍇ) {
	closed_range r = create_closed_range(3, 8);
	ASSERT_FALSE(contained_in_closed_range(r, 2));
}

TEST(��ԂɊ܂܂�邩, �傫������ꍇ) {
	closed_range r = create_closed_range(3, 8);
	ASSERT_FALSE(contained_in_closed_range(r, 9));
}

TEST(��Ԃ𕶎���ɂ���, �ʏ�) {
	char buf[20];
	closed_range r = create_closed_range(3, 8);
	ASSERT_STREQ("[3,8]", closed_range_to_str(r, buf, sizeof(buf)));
}

TEST(��Ԃ𕶎���ɂ���, �t�]�ŃG���[) {
	char buf[20];
	closed_range r = create_closed_range(8, 3);
	ASSERT_EQ(NULL, closed_range_to_str(r, buf, sizeof(buf)));
}

TEST(��Ԃ𕶎���ɂ���, �J�n�I������v���Ă��悢) {
	char buf[20];
	closed_range r = create_closed_range(5, 5);
	ASSERT_STREQ("[5,5]", closed_range_to_str(r, buf, sizeof(buf)));
}

TEST(��Ԃ���������, �������ꍇ) {
	closed_range r1 = create_closed_range(3, 8);
	closed_range r2 = create_closed_range(3, 8);
	ASSERT_TRUE(closed_range_equal(r1, r2));
}

TEST(��Ԃ���������, �������Ȃ��ꍇ) {
	closed_range r1 = create_closed_range(3, 8);
	closed_range r2 = create_closed_range(3, 7);
	ASSERT_FALSE(closed_range_equal(r1, r2));
}

TEST(��Ԃ̐ڑ�, ����Ă���ꍇ) {
	closed_range r1 = create_closed_range(3, 8);
	closed_range r2 = create_closed_range(9, 15);
	ASSERT_FALSE(closed_range_connected(r1, r2));
}

TEST(��Ԃ̐ڑ�, range1�̏I���_��range2�̊J�n�_���ڂ���ꍇ) {
	closed_range r1 = create_closed_range(3, 8);
	closed_range r2 = create_closed_range(8, 15);
	ASSERT_TRUE(closed_range_connected(r1, r2));
}

TEST(��Ԃ̐ڑ�, range2�̏I���_��range1�̊J�n�_���ڂ���ꍇ) {
	closed_range r1 = create_closed_range(15, 20);
	closed_range r2 = create_closed_range(8, 15);
	ASSERT_TRUE(closed_range_connected(r1, r2));
}

TEST(�J��ԂɊ܂܂�邩, ���Ԃ̏ꍇ) {
	open_range r = create_open_range(3, 8);
	ASSERT_TRUE(contained_in_open_range(r, 5));
}

TEST(�J��ԂɊ܂܂�邩, �J�n�_�̏ꍇ) {
	open_range r = create_open_range(3, 8);
	ASSERT_FALSE(contained_in_open_range(r, 3));
}

TEST(�J��ԂɊ܂܂�邩, �I���_�̏ꍇ) {
	open_range r = create_open_range(3, 8);
	ASSERT_FALSE(contained_in_open_range(r, 8));
}

TEST(�J��Ԃ𕶎���ɂ���, �ʏ�) {
	char buf[20];
	open_range r = create_open_range(3, 8);
	ASSERT_STREQ("(3,8)", open_range_to_str(r, buf, sizeof(buf)));
}

TEST(�J��Ԃ𕶎���ɂ���, �J�n�I������v������G���[) {
	char buf[20];
	open_range r = create_open_range(5, 5);
	ASSERT_EQ(NULL, open_range_to_str(r, buf, sizeof(buf)));
}


TEST(�J��Ԃ���������, �������ꍇ) {
	open_range r1 = create_open_range(3, 8);
	open_range r2 = create_open_range(3, 8);
	ASSERT_TRUE(open_range_equal(r1, r2));
}

TEST(�J��Ԃ���������, �������Ȃ��ꍇ) {
	open_range r1 = create_open_range(3, 8);
	open_range r2 = create_open_range(3, 7);
	ASSERT_FALSE(open_range_equal(r1, r2));
}

TEST(�J��Ԃ̐ڑ�, ����Ă���ꍇ) {
	open_range r1 = create_open_range(3, 8);
	open_range r2 = create_open_range(9, 15);
	ASSERT_FALSE(open_range_connected(r1, r2));
}

TEST(�J��Ԃ̐ڑ�, range1�̏I���_��range2�̊J�n�_���ڂ���ꍇ) {
	open_range r1 = create_open_range(3, 8);
	open_range r2 = create_open_range(7, 15);
	ASSERT_TRUE(open_range_connected(r1, r2));
}

TEST(�J��Ԃ̐ڑ�, range2�̏I���_��range1�̊J�n�_���ڂ���ꍇ) {
	open_range r1 = create_open_range(15, 20);
	open_range r2 = create_open_range(8, 16);
	ASSERT_TRUE(open_range_connected(r1, r2));
}

TEST(��Ԃ̋��ʏW��, ������Ԃ̏ꍇ) {
	char buf[20];
	closed_range r = create_closed_range(3, 8);
	closed_range result;
	closed_range* actual = intersection_of_closed_ranges(r, r, &result);
	ASSERT_STREQ("[3,8]", closed_range_to_str(*actual, buf, sizeof(buf)));
}

TEST(��Ԃ̋��ʏW��, �ꕔ�d�Ȃ�ꍇ_1�Ԗڂ���) {
	char buf[20];
	closed_range r1 = create_closed_range(3, 8);
	closed_range r2 = create_closed_range(5, 12);
	closed_range result;
	closed_range* actual = intersection_of_closed_ranges(r1, r2, &result);
	ASSERT_STREQ("[5,8]", closed_range_to_str(*actual, buf, sizeof(buf)));
}

TEST(��Ԃ̋��ʏW��, �ꕔ�d�Ȃ�ꍇ_2�Ԗڂ���) {
	char buf[20];
	closed_range r1 = create_closed_range(5, 12);
	closed_range r2 = create_closed_range(3, 8);
	closed_range result;
	closed_range* actual = intersection_of_closed_ranges(r1, r2, &result);
	ASSERT_STREQ("[5,8]", closed_range_to_str(*actual, buf, sizeof(buf)));
}

TEST(��Ԃ̋��ʏW��, �Е�����܂����ꍇ) {
	char buf[20];
	closed_range r1 = create_closed_range(1, 12);
	closed_range r2 = create_closed_range(3, 8);
	closed_range result;
	closed_range* actual = intersection_of_closed_ranges(r1, r2, &result);
	ASSERT_STREQ("[3,8]", closed_range_to_str(*actual, buf, sizeof(buf)));
}

TEST(��Ԃ̋��ʏW��, �d�Ȃ�Ȃ��ꍇ) {
	char buf[20];
	closed_range r1 = create_closed_range(3, 8);
	closed_range r2 = create_closed_range(10, 15);
	closed_range result;
	closed_range* actual = intersection_of_closed_ranges(r1, r2, &result);
	ASSERT_EQ(NULL, actual);
}