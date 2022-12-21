#include <gtest.h>

#include "queue.h"

TEST(TQueue, can_create_queue)
{
	ASSERT_NO_THROW(TQueue<int> q(4));
}

TEST(TQueue, cant_create_queue_with_negative_index)
{
	ASSERT_ANY_THROW(TQueue<int> q(-2));
}

TEST(TQueue, cant_create_queue_with_too_large_index)
{
	ASSERT_ANY_THROW(TQueue<int> q(MAX_QUEUE_SIZE + 1));
}

TEST(TQueue, can_push_element)
{
	TQueue<int> q(4);
	q.push(5);
	q.push(6);
	q.push(2);
	q.push(5);
	EXPECT_EQ(5, q.getBack());
}

TEST(TQueue, can_pop_element)
{
	TQueue<int> q(2);
	q.push(5);
	q.push(6);
	q.pop();
	EXPECT_EQ(6, q.getFront());
}

TEST(TQueue, cant_pop_element_if_queue_is_empty)
{
	TQueue<int> q(4);
	ASSERT_ANY_THROW(q.pop());
}

TEST(TQueue, can_check_if_empty)
{
	TQueue<int> q(200);
	EXPECT_EQ(1, q.isEmpty());
}

TEST(TQueue, can_check_if_full)
{
	TQueue<int> q(2);
	q.push(2);
	q.push(4);
	EXPECT_EQ(1, q.isFull());
}


