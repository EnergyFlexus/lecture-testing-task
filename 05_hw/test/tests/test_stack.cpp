#include <gtest/gtest.h>
#include <sstream>
#include <iostream>

#include "../../src/stack.h"

TEST(TestStack, TestPush)
{
	// Arrange
	Stack stack;
	initStack(&stack);

	// Act
	push(&stack, 1);
	push(&stack, 2);

	// Assert
	int current = stack.top->data;
	int current_next = stack.top->next->data;
	EXPECT_EQ(current, 2);
	EXPECT_EQ(current_next, 1);

	destroyStack(&stack);
}

TEST(TestStack, TestPop)
{
	// Arrange
	Stack stack;
	initStack(&stack);

	// Act
	push(&stack, 1);
	push(&stack, 2);
	pop(&stack);

	// Assert
	int current = stack.top->data;
	Node* current_next = stack.top->next;
	EXPECT_EQ(current, 1);
	EXPECT_EQ(current_next, nullptr);

	destroyStack(&stack);
}

TEST(TestStack, TestGetTop)
{
	// Arrange
	Stack stack;
	initStack(&stack);
	push(&stack, 1);
	push(&stack, 2);

	// Act
	int current_top = getTop(&stack)->data;

	// Assert
	EXPECT_EQ(current_top, 2);

	destroyStack(&stack);
}

TEST(TestStack, TestPushPop)
{
	// Arrange
	Stack stack;
	initStack(&stack);

	// Act
	push(&stack, 1);
	pop(&stack);

	// Assert
	bool is_empty = isEmpty(&stack);
	EXPECT_EQ(is_empty, true);

	destroyStack(&stack);
}

TEST(TestStack, TestSearchByValue)
{
	// Arrange
	Stack stack;
	initStack(&stack);
	push(&stack, 1);
	push(&stack, -2);
	push(&stack, 3);

	// Act
	Node* current_found = searchByValue(&stack, -2);
	Node* current_not_found = searchByValue(&stack, 4);

	// Assert
	EXPECT_EQ(current_found, stack.top->next);
	EXPECT_EQ(current_not_found, nullptr);

	destroyStack(&stack);
}
TEST(TestStack, TestSearchByIndex)
{
	// Arrange
	Stack stack;
	initStack(&stack);
	push(&stack, 1);
	push(&stack, -2);
	push(&stack, 3);

	// Act
	Node* current_found = searchByIndex(&stack, 1);
	Node* current_not_found = searchByIndex(&stack, 3);

	// Assert
	EXPECT_EQ(current_found, stack.top->next);
	EXPECT_EQ(current_not_found, nullptr);

	destroyStack(&stack);
}

TEST(TestStack, TestTraverseStack)
{
	testing::internal::CaptureStdout();

	// Arrange
	Stack stack;
	initStack(&stack);
	push(&stack, 1);
	push(&stack, -2);
	push(&stack, 3);
	push(&stack, -4);
	push(&stack, 0);

	// Act
	traverseStack(&stack);

	// Assert
	std::string expected = "Stack elements: 0 -4 3 -2 1 \n";
	std::string output = testing::internal::GetCapturedStdout();
	EXPECT_EQ(expected, output);

	destroyStack(&stack);
}


