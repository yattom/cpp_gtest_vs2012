#include "stdafx.h"

#include "gtest/gtest.h"
#include "closed_range.h"

TEST(�R���X�g���N�^�̈����͉��[�_�Ə�[�_�̏��Œl�����, �R���X�g���N�^�̈����͉��[�_���R�Ə�[�_�͂W�����)
{
	ClosedRange cr = ClosedRange(3, 8);
}

TEST(���[�_���擾����, ���[�_���R�ł���)
{
	ClosedRange cr = ClosedRange(3, 8);

	ASSERT_EQ(3, cr.getLower());
}


TEST(��[�_���擾����, ��[�_���W�ł���)
{
	ClosedRange cr = ClosedRange(3, 8);

	ASSERT_EQ(8, cr.getUpper());
}


TEST(�R���X�g���N�^�̈���, ���[�_����[�_)
{
	ASSERT_NO_THROW(ClosedRange(3, 8));
}

TEST(�R���X�g���N�^�̈���, ���[�_����[�_)
{
	ASSERT_ANY_THROW(ClosedRange(8, 3));
}

TEST(�R���X�g���N�^�̈���, ���[�_����[�_)
{
	ASSERT_NO_THROW(ClosedRange(3, 3));
}
