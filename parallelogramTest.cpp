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
  float firstFloat = 2.0;
  float secondFloat = 3.0;
  float angleFloat = 45.0;
  float area = 4.2426405;
  float perimeter;

  // float angleInRadians = angleFloat * (pi / 180);
  // float area, perimeter;
  float angleInRadians = angleFloat * (pi / 180);
  float expected_area = firstFloat*secondFloat*sin(angleInRadians);
  float expected_perimeter = (firstFloat + secondFloat)*2;
  
  ParallelogramFormula(firstFloat, secondFloat, angleFloat, &perimeter);
  
  EXPECT_FLOAT_EQ(expected_area, area);
  EXPECT_FLOAT_EQ(expected_perimeter, perimeter);
}