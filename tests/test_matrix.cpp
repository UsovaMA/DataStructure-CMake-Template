// Copyright 2022 Marina Usova

#include <gtest.h>
#include "../lib_matrix/matrix.h"

TEST(TDynamicMatrix, can_create_matrix_with_positive_length) {
  ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix) {
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length) {
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix) {
  TDynamicMatrix<int> m(5);
  ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one) {
  TDynamicMatrix<int> m(5);
  TDynamicMatrix<int> n(m);
  EXPECT_EQ(m, n);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory) {
  TDynamicMatrix<int> m(5);
  TDynamicMatrix<int> n(m);
  EXPECT_NE(&n, &m);
}

TEST(TDynamicMatrix, can_get_size) {
  TDynamicVector<int> m(5);
  EXPECT_EQ(5, m.size());
}

TEST(TDynamicMatrix, can_set_and_get_element) {
	TDynamicVector<int> m(10);
	m[3] = 7;
	EXPECT_EQ(m[3], 7);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index) {
	TDynamicMatrix<int> m(5);
	ASSERT_ANY_THROW(m[-1]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index) {
	TDynamicMatrix<int> m(5);
	ASSERT_ANY_THROW(m[5]);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself) {
  TDynamicMatrix<int> m(5);
  ASSERT_NO_THROW(m = m);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size) {
  TDynamicMatrix<int> m(5);
  TDynamicMatrix<int> n(5);
  ASSERT_NO_THROW(m = n);

}

TEST(TDynamicMatrix, assign_operator_change_matrix_size) {
  TDynamicMatrix<int> m(4);
  TDynamicMatrix<int> n(6);
  m = n;
  EXPECT_EQ(6, m.size());
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size) {
  TDynamicMatrix<int> m(4);
  TDynamicMatrix<int> n(5);
  ASSERT_NO_THROW(m = n);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true) {
  TDynamicMatrix<int> m(4);
  TDynamicMatrix<int> n(m);
  EXPECT_EQ(true, m == n);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true) {
	TDynamicMatrix<int> m(4);
	EXPECT_EQ(true, m == m);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal) {
	TDynamicMatrix<int> m(4);
	TDynamicMatrix<int> n(5);
	EXPECT_EQ(false, m == n);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size) {
	TDynamicMatrix<int> m(3);
	TDynamicMatrix<int> n(3);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			m[i][j] = 0;
			n[i][j] = 0;
		}
	}
	ASSERT_NO_THROW(m + n);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size) {
	TDynamicMatrix<int> m(3);
	TDynamicMatrix<int> n(4);
	ASSERT_ANY_THROW(m + n);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size) {
  ADD_FAILURE();
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size) {
  ADD_FAILURE();
}
