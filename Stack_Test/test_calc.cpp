#include "../mp2-lab3-stack -forgit/TCalc.h"

#include "gtest.h"

TEST(TCalc, can_create_calc_with_right_infix)
{
	TCalc calc("2+2");
	std::string str = "2+2";
	EXPECT_EQ(1, str == calc.GetInfix());
}

TEST(TCalc, can_set_infix)
{
	TCalc calc("3-3");
	std::string str = "2+2";
	calc.SetInfix(str);
	EXPECT_EQ(1, str == calc.GetInfix());
}

TEST(TCalc, can_translate_infix_to_postfix)
{
	TCalc calc("2+2");
	
	std::string str = "22+";
	EXPECT_EQ(1, str == calc.GetPostfix());
}

TEST(TCalc, can_correctly_calculate_with_postfix)
{
	TCalc calc("2+2*3-(1+1)");
	EXPECT_EQ(6, calc.CalculateWithPostfix());
}

TEST(TCalc, can_correctly_calculate_no_postfix)
{
	TCalc calc("2+2*3-(1+1)");
	EXPECT_EQ(6, calc.CalculateNoPostfix());
}

