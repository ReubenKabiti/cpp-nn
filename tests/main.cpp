#include <gtest/gtest.h>
#include "Matrix.h"

TEST(Matrices, SetAndGetValue)
{
	Matrix m(2, 2);
	m.set(1, 1, 101);
	ASSERT_EQ(m.get(1, 1), 101);
}

TEST(Matrices, MultiplyingTwoMatrices)
{
	Matrix mat1(2, 2);
	Matrix mat2(2, 2);

	mat1.set(0, 0, 1);
	mat1.set(0, 1, 2);
	mat1.set(1, 0, 3);
	mat1.set(1, 1, 4);

	mat2.set(0, 0, 4);
	mat2.set(0, 1, 2);
	mat2.set(1, 0, 6);
	mat2.set(1, 1, 7);
	auto res = mat1 * mat2;

	ASSERT_EQ(res.get(0, 0), 16);
	ASSERT_EQ(res.get(0, 1), 16);
	ASSERT_EQ(res.get(1, 0), 36);
	ASSERT_EQ(res.get(1, 1), 34);
}

int main(int argc, char *argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
