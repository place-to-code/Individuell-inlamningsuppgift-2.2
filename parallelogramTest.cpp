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
#include "shapes.h"
}

class ShapesTest : public testing::Test {
protected:
	void SetUp() override //some needed code 
  {
		 
	}
};


TEST(ParollelogramFormulaTest, CalculateAreaAndPerimeter) {
  const float pi = 3.1415926535; 
  float firstFloat = 7.0;
  float secondFloat = 11.0;
  float angleFloat = 60.0;
  float perimeter;


  float angleInRadians = angleFloat * (pi / 180);
  float expected_area = firstFloat*secondFloat*sin(angleInRadians);
  float expected_perimeter = (firstFloat + secondFloat)*2;
  
  float area = ParallelogramFormula(firstFloat, secondFloat, angleFloat, &perimeter);
 
  EXPECT_FLOAT_EQ(expected_area, area);
  EXPECT_FLOAT_EQ(expected_perimeter, perimeter);
}

TEST(RectangleFormulaTest, CalculateAreaAndPerimeterOfRectangle) {
  
  float firstFloat = 7.0;
  float secondFloat = 11.0;
  float expected_area = firstFloat*secondFloat;
  float expected_perimeter = (firstFloat + secondFloat)*2;
  float perimeter; 
  float area = RectangleFormula(firstFloat, secondFloat, &perimeter);
 
  EXPECT_FLOAT_EQ(expected_area, area);
  EXPECT_FLOAT_EQ(expected_perimeter, perimeter);
}