// Copyright 2022 Maxim Filatov

#include <gtest.h>
#include "../lib_example/example.h"

#define EPSILON 0.000001

TEST(test_lib, can_plus_test) {
  // Arrange
  int x = 10;
  int y = 2;

  // Act & Assert
  ASSERT_NO_THROW(plus(x, y));
}

TEST(test_lib, can_plus_correctly_test) {
  // Arrange
  int x = 6;
  int y = 2;

  // Act
  int result = plus(x, y);

  // Assert
  int expected_result = 8;
  EXPECT_EQ(expected_result, result);
}
