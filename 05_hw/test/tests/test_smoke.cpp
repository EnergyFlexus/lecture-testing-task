#include <gtest/gtest.h>

#include "../../src/stack.h"

TEST(SmokeStack, TestInitDestroy)
{
	// Arrange
	Stack stack;

	// Act
	initStack(&stack);
	destroyStack(&stack);

	// Assert
	SUCCEED();
}
TEST(SmokeStack, TestEmpty)
{
	// Arrange
	Stack stack;
	initStack(&stack);

	// Act
	bool is_empty = isEmpty(&stack);

	// Assert
	EXPECT_EQ(is_empty, true);

	destroyStack(&stack);
}
