#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>  
#include <math.h> 

#include "calculator.h" 
#include "game.h" 
#include "shapes.h" 
 
void getMenuSelection()
{
    int choice;
    char input[1000000]; 

    while(1){
    printf ("\n");
    printf("Menu\n");
    printf("1. Shapes\n");
    printf("2. Mini Calculator\n");
    printf("3. Rock, Paper, Scissors\n");


    while(1)
    {   
        printf ("Enter your choice: ");
        fgets (input, sizeof(input), stdin);
        
        choice = atoi(input);      
        if ((choice == 1)||
        (choice == 2)|| 
        (choice == 3))
        {                          
        break;
        } 
        else
        {
        printf ("You can enter only 1, 2, 3! \n");                    
        }     
    }  

    switch (choice)
    {
    case 1:
            Shapes ();
            break;
        case 2:
            MiniCalculator();
            break;
        case 3:
            RockPaperScissors();
            break;        
        default:     //does nothing, because it can be entered only 1,2,3,4
            break;
        }
    }
}

int main()
{
    while (1)        
    {                
    getMenuSelection();
    }
}