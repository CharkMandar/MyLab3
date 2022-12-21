#include <gtest.h>

#include <stack.h>

TEST(stack, can_create_stack)
{
	ASSERT_NO_THROW(TStack<int> s(6));
}

TEST(stack, cant_create_stack_with_negative_index)
{
	ASSERT_ANY_THROW(TStack<int> s(-1));
}

TEST(stack, cant_create_stack_with_too_large_index)
{
	ASSERT_ANY_THROW(TStack<int> s(MAX_MEM_SIZE + 1));
}

TEST(stack, can_push_element)
{
	TStack<int> s(3);
	s.push(6);
	s.push(5);
	EXPECT_EQ(5, s.getTop());
}

TEST(stack, push_extends_memory_if_full)
{
	TStack<int> s(2);
	s.push(4);
	s.push(3);
	s.push(6);
	EXPECT_EQ(3, s.getSize());
}

TEST(stack, can_pop_element)
{
	TStack<int> s(3);
	s.push(4);
	s.push(2);
	s.push(9);
	s.pop();
	EXPECT_EQ(2, s.getSize());

}

TEST(stack, cant_pop_empty_stack)
{
	TStack<int> s(3);
	ASSERT_ANY_THROW(s.pop());
}
TEST(stack, can_get_size)
{
	TStack<int> s(2);
	s.push(4);
	s.push(3);
	EXPECT_EQ(2, s.getSize());
}

TEST(stack, can_chek_if_full)
{
	TStack<int> s(2);
	s.push(1);
	s.push(2);
	EXPECT_EQ(1, s.isFull());
}
TEST(stack, can_check_if_empty)
{
	TStack<int> s(100);
	EXPECT_EQ(1, s.isEmpty());
}
