#include "stdafx.h"

#include "gtest/gtest.h"
#include "closed_range.h"

TEST(�R���X�g���N�^�̈����͉��[�_�Ə�[�_�̏��Œl�����, �R���X�g���N�^�̈����͉��[�_���R�Ə�[�_�͂W�����)
{
	ClosedRange cr = ClosedRange(3, 8);
}

TEST(�y��ԁz�Q�b�^�[�֐�, ���[�_���R�ɐݒ肵����R���擾�ł���)
{
	ClosedRange cr = ClosedRange(3, 8);

	ASSERT_EQ(3, cr.getLower());
}

TEST(�y��ԁz�Q�b�^�[�֐�, ��[�_���W�ɐݒ肵����W���擾�ł���)
{
	ClosedRange cr = ClosedRange(3, 8);

	ASSERT_EQ(8, cr.getUpper());
}

TEST(�y��ԁz�R���X�g���N�^�̈����`�F�b�N, ���[�_����[�_�̏ꍇ�̓G���[�Ƃ��ė�O�𓊂��Ȃ�)
{
	ASSERT_NO_THROW(ClosedRange(3, 8));
}

TEST(�y��ԁz�R���X�g���N�^�̈����`�F�b�N, ���[�_����[�_�̏ꍇ�̓G���[�Ƃ��ė�O�𓊂���)
{
	ASSERT_ANY_THROW(ClosedRange(8, 3));
}

TEST(�y��ԁz�R���X�g���N�^�̈����`�F�b�N, ���[�_����[�_�̏ꍇ�̓G���[�Ƃ��ė�O�𓊂��Ȃ�)
{
	ASSERT_NO_THROW(ClosedRange(3, 3));
}

TEST(�y��ԁz��ԓ��O�̔���, 3�A8�̂Ƃ�5�͋�ԓ��ł���)
{
	ClosedRange cr = ClosedRange(3, 8);
	ASSERT_TRUE(cr.contains(5));
}

TEST(�y��ԁz��ԓ��O�̔���, 3�A8�̂Ƃ�9�͋�ԊO�ł���)
{
	ClosedRange cr = ClosedRange(3, 8);
	ASSERT_FALSE(cr.contains(9));
}

TEST(�y��ԁz��ԓ��O�̔���, 3�A8�̂Ƃ�2�͋�ԊO�ł���)
{
	ClosedRange cr = ClosedRange(3, 8);
	ASSERT_FALSE(cr.contains(2));
}

TEST(�y��ԁz��ԉ��[�̒l, 3�A8�̂Ƃ�3�͋�ԓ��ł���)
{
	ClosedRange cr = ClosedRange(3, 8);

	ASSERT_TRUE(cr.contains(3));
}

TEST(�y��ԁz��ԏ�[�̒l, 3�A8�̂Ƃ�8�͋�ԓ��ł���)
{
	ClosedRange cr = ClosedRange(3, 8);

	ASSERT_TRUE(cr.contains(8));
}

TEST(�y��ԁz��ԓ��m�̔�r,�������ꍇ��True��Ԃ�_3�`8��3�`8)
{
	ClosedRange cr_a = ClosedRange(3, 8);
	ClosedRange cr_b = ClosedRange(3, 8);

	ASSERT_TRUE(cr_a.equals(cr_b));
}

TEST(�y��ԁz��ԓ��m�̔�r,�������Ȃ��ꍇ��false��Ԃ�_3�`8��1�`6)
{
	ClosedRange cr_a = ClosedRange(3, 8);
	ClosedRange cr_b = ClosedRange(1, 6);

	ASSERT_FALSE(cr_a.equals(cr_b));
}

TEST(�y��ԁz��ԓ��m�̐ڑ�,�܂������d�Ȃ��Ă��Ȃ��ꍇ��False��Ԃ�_3�`8��1�`2)
{
	ClosedRange cr_a = ClosedRange(3, 8);
	ClosedRange cr_b = ClosedRange(1, 2);

	ASSERT_FALSE(cr_a.isConnectedTo(cr_b));
}

TEST(�y��ԁz��ԓ��m�̐ڑ�,�܂������d�Ȃ��Ă��Ȃ��ꍇ��False��Ԃ�_3�`8��9�`10)
{
	ClosedRange cr_a = ClosedRange(3, 8);
	ClosedRange cr_b = ClosedRange(9, 10);

	ASSERT_FALSE(cr_a.isConnectedTo(cr_b));
}

TEST(�y��ԁz��ԓ��m�̐ڑ�,���A�̏���ƕ��B�̉�������v���Ă���ꍇ��True��Ԃ�)
{
	ClosedRange cr_a = ClosedRange(3, 8);
	ClosedRange cr_b = ClosedRange(8, 10);

	ASSERT_TRUE(cr_a.isConnectedTo(cr_b));
}

TEST(�y��ԁz��ԓ��m�̐ڑ�,���A�̉����ƕ��B�̏������v���Ă���ꍇ��True��Ԃ�)
{
	ClosedRange cr_a = ClosedRange(3, 8);
	ClosedRange cr_b = ClosedRange(1, 3);

	ASSERT_TRUE(cr_a.isConnectedTo(cr_b));
}


TEST(�y��ԁz��ԓ��m�̐ڑ�,���A�͈͓̔��ɕ��B�����荞��ł���ꍇ��True��Ԃ�)
{
	ClosedRange cr_a = ClosedRange(3, 8);
	ClosedRange cr_b = ClosedRange(4, 6);

	ASSERT_TRUE(cr_a.isConnectedTo(cr_b));
}

TEST(�y��ԁz��ԓ��m�̐ڑ�,���A�����B�͈͓̔��ɓ��荞��ł���ꍇ��True��Ԃ�)
{
	ClosedRange cr_a = ClosedRange(3, 8);
	ClosedRange cr_b = ClosedRange(1, 10);

	ASSERT_TRUE(cr_a.isConnectedTo(cr_b));
}

