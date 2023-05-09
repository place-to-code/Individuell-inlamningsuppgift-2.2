#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>  
#include <math.h> 

float  CheckStatistics(float* win, float* total)
{
    char line[250];
    *win = 0;
    *total = 0;
    float ratio;

FILE *file;
file = fopen ("records.txt", "r");        // read file records.txt
if (file == NULL){                      //checking if file can be open. If name is wrong returns NULL;
printf  ("Read Error! File Not Found!)\n");
file = fopen ("records.txt", "r");  
}

 
while (fgets(line, sizeof(line), file) != NULL)  
{   
    if (strstr(line, "Human") != NULL) 
    { 
        (*win)++;
    }

    if ( strstr(line, "win") != NULL)
    {
        (*total)++;
    }
}
fclose(file); 
// ratio = (*win+1)/(*total+1)*100;
// printf ("You won %.0f times of %.0f games. Your ratio is %.0f\%\n", *win+1, *total+1, ratio);
return *win, *total;
}




bool SaveInFile(iWin)
{


float win;
float total;
CheckStatistics(&win,&total);
float ratioIfWin = (win+1)/(total+1)*100;
float ratioIfLose = (win)/(total+1)*100;

struct tm *time_info; 
time_t current_time;                                 
char time_string[50]; 
time(&current_time);
time_info = localtime(&current_time);
bool winOrLose = false;

strftime(time_string, sizeof(time_string), "%d/%m/%Y %H:%M:%S", time_info);
FILE *file;

file = fopen ("records.txt", "r");        // read file records.txt
if (file == NULL){                      //checking if file can be open. If name is wrong returns NULL;
printf  ("Read Error! File Not Found! But I created one for you! ;)\n");  
}
file = fopen ("records.txt", "a"); //all a new line and not delete old info/ 
if (iWin)
    {
    fprintf (file, "Human win \t%-10s\t ratio %.0f\%\n",  time_string, ratioIfWin); 

    fclose(file);
    }
    else
    {
    fprintf (file, "Robot win \t%-10s\t ratio %.0f\%\n",  time_string, ratioIfLose); 

    fclose(file);
    }

}

void RockPaperScissors()
{
printf ("Rock Paper Scissors!");
printf ("\n");
printf ("Let's play!\n");
Sleep(80);                        
printf ("Rock...\n");
Sleep(80);                          
printf ("Paper...\n");
Sleep(80);                           
printf ("Stone...\n");
Sleep(500);                           
printf ("Shoot!\n");
Sleep(100);  
printf ("\n");
srand (time(NULL));                                
int random =  rand() %3 + 1;  

if (random ==1)
{
    printf ("Stone!\n");
}               
if (random ==2)
{
    printf ("Scissors!\n");
} 
if (random ==3)
{
    printf ("Paper!\n");
}       
Sleep(200);  

printf ("Hmmm...Did I win? Y/N\n");
char answer[2];

while (1)
{   bool iWin = false;
  
    fgets(answer, sizeof(answer), stdin);
    answer[strcspn(answer, "\n")] = '\0';

    if (strchr(answer, 'Y') != NULL || strchr(answer, 'y') != NULL)
    {   
        printf("\n");
        printf("Hehe! Hail all robots!\n");
        SaveInFile(iWin);
        break;
    }
    else if (strchr(answer, 'N') != NULL || strchr(answer, 'n') != NULL)
    {   
        printf("\n");
        printf("You are lucky, meatbag!\n");
        iWin = true;
        SaveInFile(iWin);
        break;
    }
    else
    {
        printf("\nDo not try to cheat, meatbag!\nI ask you again, did I win? ");
        while ((getchar()) != '\n');
    }
 
}
// CheckStatistics();
printf ("Press any key to continue...\n");
getch();

}
