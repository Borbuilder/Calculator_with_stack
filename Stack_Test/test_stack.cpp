#include "../mp2-lab3-stack -forgit/TStack.h"
#include "gtest.h"

TEST(TStack, can_create_stack_with_positive_MaxSize)
{
    ASSERT_NO_THROW(TStack<int> st(5));
}

TEST(TStack, throws_when_create_stack_with_negative_size)
{
	ASSERT_ANY_THROW(TStack<int> st(-5));
}

TEST(TStack, can_create_copied_stack)
{
  TStack<int> st(5);
  for (int i = 1; i <= 5; i++)
  {
		st.Push(i);
  }
  ASSERT_NO_THROW(TStack<int> st1(st));
  EXPECT_EQ(1, 1);
}

TEST(TStack, copied_vector_is_equal_to_source_one)
{
	const int size = 5;
	TStack<int> st(size);
	for (int i = 1; i <= 5; i++)
	{
		st.Push(i);
	}
	TStack<int> st1(st);
	for (int i = 1; i <= 5; i++)
	{
		EXPECT_EQ(st.Pop(), st1.Pop());
	}
	
}

TEST(TStack, copied_stack_has_its_own_memory)
{
	TStack<int> st(5);
	for (int i = 1; i <= 5; i++)
	{
		st.Push(i);
	}
	TStack<int> st1(st);
	EXPECT_EQ(0, &st == &st1);
}

TEST(TStack, can_correctly_compare_two_equal_stacks)
{
	TStack<int> st(5);
	for (int i = 1; i <= 5; i++)
	{
		st.Push(i);
	}
	TStack<int> st1(5);
	for (int i = 1; i <= 5; i++)
	{
		st1.Push(i);
	}
	EXPECT_EQ(1, st == st1);
}

TEST(TStack, can_correctly_compare_two_not_equal_stacks)
{
	TStack<int> st(5);
	for (int i = 1; i <= 5; i++)
	{
		st.Push(i);
	}
	TStack<int> st1(5);
	for (int i = 1; i <= 5; i++)
	{
		st1.Push(i+1);
	}
	EXPECT_EQ(1, st != st1);
}

TEST(TStack, can_assign_stack_to_itself)
{
	TStack<int> st(5);
	ASSERT_NO_THROW(st = st);
}

TEST(TStack, can_assign_stacks_of_equal_size)
{
	TStack<int> st(5);
	TStack<int> st1(5);
	for (int i = 1; i <= 5; i++)
	{
		st.Push(i);
	}
	for (int i = 1; i <= 5; i++)
	{
		st1.Push(i+1);
	}
	ASSERT_NO_THROW(st = st1);
	st = st1;
	for (int i = 1; i <= 5; i++)
	{
		EXPECT_EQ(st.Pop(), st1.Pop());
	}
}

TEST(TStack, can_assign_stacks_of_different_size)
{
	TStack<int> st(5);
	for (int i = 1; i <= 5; i++)
	{
		st.Push(i);
	}
	TStack<int> st1(10);
	for (int i = 1; i <= 10; i++)
	{
		st1.Push(i);
	}
	st = st1;
	for (int i = 1; i <= 10; i++)
	{
		EXPECT_EQ(st.Pop(), st1.Pop());
	}
}

TEST(TStack, new_stack_is_empty)
{
	TStack<int> st(5);
	EXPECT_EQ(1, st.empty());
}

TEST(TStack, stack_with_elements_is_not_empty)
{
	TStack<int> st(5);
	st.Push(1);
	st.Push(2);
	EXPECT_EQ(0, st.empty());
}

TEST(TStack, filled_stack_is_full)
{
	TStack<int> st(5);
	for (int i = 1; i <= 5; i++)
	{
		st.Push(i);
	}
	EXPECT_EQ(1, st.full());
}

TEST(TStack, not_filled_stack_is_not_full)
{
	TStack<int> st(5);
	for (int i = 1; i <= 4; i++)
	{
		st.Push(i);
	}
	EXPECT_EQ(0, st.full());
}

TEST(TStack, can_get_number_of_elements)
{
	TStack<int> st(5);
	st.Push(1);
	st.Push(2);
	EXPECT_EQ(2, st.ElementsNumber());
}

TEST(TStack, throws_when_output_empty_stack)
{
	TStack<int> st(5);
	ASSERT_ANY_THROW(st.output());
}

TEST(TStack, can_push)
{
	TStack<int> st(5);
	ASSERT_NO_THROW(st.Push(1));
}

TEST(TStack, can_pop)
{
	TStack<int> st(5);
	st.Push(1);
	ASSERT_NO_THROW(st.Pop());
}

TEST(TStack, can_not_push_to_filled_stack)
{
	TStack<int> st(5);
	for (int i = 1; i <= 5; i++)
	{
		st.Push(i);
	}
	ASSERT_ANY_THROW(st.Push(1));
}

TEST(TStack, can_not_pop_from_empty_stack)
{
	TStack<int> st(5);
	ASSERT_ANY_THROW(st.Pop());
}

TEST(TStack, can_not_get_top_from_empty_stack)
{
	TStack<int> st(5);
	ASSERT_ANY_THROW(st.Top());
}

TEST(TStack, can_get_right_top)
{
	TStack<int> st(5);
	st.Push(1);
	st.Push(2);
	EXPECT_EQ(2,st.Top());
}

TEST(TStack, can_clear_stack)
{
	TStack<int> st(5);
	for (int i = 1; i <= 5; i++)
	{
		st.Push(i);
	}
	st.ClerStack();
	EXPECT_EQ(1, st.empty());
}
