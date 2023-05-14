#include <gtest/gtest.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>  
#include <math.h> 

//ATTENTION! Wait about 15 seconds to finish the tests!!!

//This test checks if random generator gives values evenly.
//it will be run 100 times och get 100 generated numbers
//because it generates random depending on current time, 
//we need a pause (100 ms) to get en even results
//expected value is 100/3 = 33 and normal deviation for that is 10
//so normally it will be generate each number in the range 23-43 (33 - 10 and 33+10)
//so this test will be passad almost always


extern "C" 
{
#include "game.h"
}

class ShapesTest : public testing::Test {
protected:
	void SetUp() override   
  {
		 
	}
};

TEST(RandomFormulaforGameTest, CalculateAmmountOfRandom) {
int one = 0;
int two = 0;
int three = 0;
int random;

  for (int i = 0; i < 100; i++)
  {
    random = randomFormulaForGame(); 
    _sleep(100);     
 
    if (random ==1)
    {
        one++;
    }               
    if (random ==2)
    {
        two++;
    } 
    if (random ==3)
    {
        three++;
    }  
 }
 printf ("%d\n", one);
 printf ("%d\n", two);
 printf ("%d\n", three);

 

  EXPECT_TRUE( one >= 23 && one <= 43); 
  EXPECT_TRUE( two >= 22 &&  two <= 43); 
  EXPECT_TRUE( three >= 22 &&  three <= 43);
  
}

