#include <gtest/gtest.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>  
#include <math.h> 

extern "C" 
{
#include "calculator.h"
}

class ShapesTest : public testing::Test {
protected:
	void SetUp() override //some needed code 
  {
		 
	}
};


TEST(ExtractingTest, ExtractOneNumberFromAnother)
{
 
  float firstFloat = 7.0;
  float secondFloat = 11.0;
  float result;
  float expected_result = firstFloat-secondFloat;
  result = extractingFormula(firstFloat, secondFloat);
 
 
  EXPECT_FLOAT_EQ(expected_result, result);
  
}
TEST(addingTest, AddingOneNumberToAnother)
{
 
  float firstFloat = 7.0;
  float secondFloat = 11.0;
  float result;
  float expected_result = firstFloat+secondFloat;
  result = addingFormula(firstFloat, secondFloat);
 
 
  EXPECT_FLOAT_EQ(expected_result, result);
  
}
TEST(MultiplyingTest, MultiplyOneNumberWithAnother)
{
 
  float firstFloat = 7.0;
  float secondFloat = 11.0;
  float result;
  float expected_result = firstFloat*secondFloat;
  result = multiplyingFormula(firstFloat, secondFloat);
 
 
  EXPECT_FLOAT_EQ(expected_result, result);
  
}
TEST(DevidingTest, DevideOneNumberByAnother)
{
    //Deviding by 0 is controlled with input

  float firstFloat = 7.0;
  float secondFloat = 11.0;
  float result;
  float expected_result = firstFloat/secondFloat;
  result = devidingFormula(firstFloat, secondFloat);
 
 
  EXPECT_FLOAT_EQ(expected_result, result);
  
}
TEST(ModulisTest, ModulusOneNumberFromAnother)
{
 
  int firstInt = 11.0;
  int secondInt = 7.0;
  int result;
  int expected_result = firstInt % secondInt;
  result = extractingFormula(firstInt, secondInt);
 
 
  EXPECT_FLOAT_EQ(expected_result, result);
  
}
