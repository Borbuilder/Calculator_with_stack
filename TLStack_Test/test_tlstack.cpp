#include "../FwrdList_Stack/TLStack.h"
#include "gtest.h"

TEST(TLStack, can_create_stack_with_positive_size)
{
    ASSERT_NO_THROW(TLStack<int> st());
}


TEST(TLStack, can_get_length)
{
    TLStack<int> st;
    int i = st.ElementsNumber();
    EXPECT_EQ(0, i);
}


TEST(TLStack, new_stack_is_empty)
{
    TLStack<int> st;
    EXPECT_EQ(1,st.empty());
}


TEST(TLStack, can_push_and_pop)
{
    TLStack<int> st;
    int a1 = 1;
    int a2 = 2;
    int a3 = 3;
    ASSERT_NO_THROW(st.Push(a1));
    ASSERT_NO_THROW(st.Push(a2));
    ASSERT_NO_THROW(st.Push(a3));
    int b1, b2, b3;
    ASSERT_NO_THROW(b1 = st.Pop());
    ASSERT_NO_THROW(b2 = st.Pop());
    ASSERT_NO_THROW(b3 = st.Pop());
    EXPECT_EQ(a1, b3);
    EXPECT_EQ(a2, b2);
    EXPECT_EQ(a3, b1);
}

TEST(TLStack, throws_when_use_pop_on_empty_stack)
{
    TLStack<int> st;
    ASSERT_ANY_THROW(st.Pop());
}


TEST(TLStack, throws_when_use_TOP_on_empty_stack)
{
    TLStack<int> st;
    ASSERT_ANY_THROW(st.Top());
}

TEST(TLStack, return_true_when_use_Empty_on_empty_stack)
{
    TLStack<int> st;
    bool b1 = st.empty();
    EXPECT_EQ(1, b1);
}
TEST(TLStack, return_false_when_use_Empty_on_not_empty_stack)
{
    TLStack<int> st;
    st.Push(1);
    st.Push(1);
    bool b1 = st.empty();
    EXPECT_EQ(0, b1);
}
