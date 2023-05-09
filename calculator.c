#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>  
#include <math.h> 

void MiniCalculator()  
{
printf ("Mini Calculator!\n");    
char first[10000];
char second[10000];
float sum;
char whatToDo[2];

while (1)
    {
    printf ("Enter first number: ");
    fgets (first, sizeof(first), stdin);
    first[strcspn(first, "\n")] = '\0';  


        if (strspn(first, "0123456789.") == strlen(first))  //dot is decimal point i C 
        //checking if entered has symbols 1234567890 and . as a decimal point
        //If first symbol is . it goes as 0.x by default
        {                                        
            break;  
        } 
            else
        {
            printf ("You can enter only numbers and decimal point \".\"! \n");                    
        }    

    }
    float firstFloat = atof (first); //convert char to float

    while (1)
    {
    printf ("Enter second number: ");
    fgets (second, sizeof(second), stdin);
    second[strcspn(second, "\n")] = '\0';  
 

        if (strspn(second, "0123456789.") == strlen(second))   
        {                                        
            break;  
        } 
            else
        {
            printf ("You can enter only numbers! \n");                    
        }    

    }


    float secondFloat = atof (second);

printf ("What to you want to do? \n");
printf ("\n");
printf ("Adding: + \n");
printf ("Extracting: - \n");
printf ("Multiplying: * \n");
printf ("Dividing: / \n");
printf ("Modulus: \% \n");
scanf (" %c", &whatToDo[0]);

                                        //!!!safe input fix 

if (strcmp(&whatToDo,"+")==0)
{
    sum = firstFloat + secondFloat;
    printf ("The answer is %.2f\n", sum); 
}

if (strcmp(&whatToDo,"-")==0)
{
    sum = firstFloat - secondFloat;
}

if (strcmp(&whatToDo,"*")==0)
{
    sum = firstFloat * secondFloat;
    printf ("The answer is %.2f\n", sum); 
}

if (strcmp(&whatToDo,"/")==0)
{

    if (secondFloat == 0)
    {
         printf ("You cant devide by 0!\n");
    }
    else
    {
    sum = firstFloat/secondFloat;
    printf ("The answer is %.2f\n", sum);
    }
     
}

if (strcmp(&whatToDo,"%")==0)
{   
    int firstInt = (int) round (firstFloat);
    int secondInt = (int) round (secondFloat);
    sum = firstInt % secondInt;
    printf ("The answer is %.2f\n", sum); 
}

printf ("Press any key to continue...\n");
getch();
}