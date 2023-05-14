#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <time.h>  
#include <math.h> 

float TriangleFormula (float firstFloat, float secondFloat, float angleFloat, float* perimeter)
{
    const float pi = 3.1415926535;  
    float angleInRadians = angleFloat * (pi / 180); //convert degrees in radians
    float area = 0.5*firstFloat*secondFloat*sin(angleInRadians); 
    *perimeter = firstFloat + secondFloat + sqrt(firstFloat * firstFloat + secondFloat * secondFloat - 2 * firstFloat * secondFloat * cos(angleInRadians));
    return area;
}

float CircelFormula (float radiusFloat,  float* circumference)
{
    const float pi = 3.1415926535;  
    float area;
    area = pi*radiusFloat*radiusFloat;
    *circumference = 2*pi*radiusFloat;
    return area;
}

float RectangleFormula (float firstFloat, float secondFloat, float* perimeter)
{

    float area = firstFloat*secondFloat;
    *perimeter = (firstFloat + secondFloat)*2;
    return area;
}

float ParallelogramFormula (float firstFloat, float secondFloat, float angleFloat, float* perimeter)
{
    const float pi = 3.1415926535;  
    float angleInRadians = angleFloat * (pi / 180);
    float area = firstFloat*secondFloat*sin(angleInRadians);
    *perimeter = (firstFloat + secondFloat)*2;
    return area;
}

float Rectangle()
{
    printf("This is Rectangle!\n");
    char first[50];
    char second[50];
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
            printf ("You can enter only numbers and decimal point \".\"! \n");                    
        }    

    }


    float secondFloat = atof (second);
    float area;
    float perimeter;
    area = RectangleFormula (firstFloat, secondFloat, &perimeter);
    printf ("The area of the rectangle is %.2f: ", area );
    printf ("\nThe perimeter of the rectangle is %.2f: ", perimeter);
    printf ("\nPress any key to continue...\n");
    getch();
}

float Parallelogram() //should be called parallelogramInput, formula is in separare function
{
    const float pi = 3.1415926535;  
    printf("This is Parallelogram!\n");

    char first[50];
    char second[50];
    char angle[50];
    float angleFloat;
 while (1)
    {
    printf ("Enter first side: ");
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
    printf ("Enter second side: ");
    fgets (second, sizeof(second), stdin);
    second[strcspn(second, "\n")] = '\0';  
 

        if (strspn(second, "0123456789.") == strlen(second))   
        {                                        
            break;  
        } 
            else
        {
            printf ("You can enter only numbers and decimal point \".\"! \n");                    
        }    

    }


    float secondFloat = atof (second);

    while (1)
    {
    printf ("Enter the angle in degrees: ");
    fgets (angle, sizeof(angle), stdin);
    angle[strcspn(angle, "\n")] = '\0';  
 

        if (strspn(angle, "0123456789.") == strlen(angle))   
        {                                        
            angleFloat = atof (angle); 
            if (angleFloat >0 &&angleFloat <=360 ) 
            {
                break;
            }
            else
            {
                printf ("You can enter only numbers between 0 and 360! \n"); 
            }     
        } 
            else
        {
            printf ("You can enter only numbers and decimal point \".\"! \n");                    
        }    

    }

    //  here we call formula, get back area as return but we take perimeter from memory
    // because function can return only one value
    float perimeter;
    float area = ParallelogramFormula (firstFloat,  secondFloat,  angleFloat, &perimeter);
  
    printf ("The area of the parallogram is %.2f: ", area );
    printf ("\nThe perimeter of the parallelogram is %.2f: ", perimeter);
    printf ("\nPress any key to continue...\n");
    getch();

}

float Triangle()
{
    const float pi = 3.1415926535;  
    printf("This is Triangle!\n");
    char first[50];
    char second[50];
    char angle[50];
    float angleFloat;
 while (1)
    {
    printf ("Enter first side of triangel: ");
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
    printf ("Enter second side of triangel: ");
    fgets (second, sizeof(second), stdin);
    second[strcspn(second, "\n")] = '\0';  
 

        if (strspn(second, "0123456789.") == strlen(second))   
        {                                        
            break;  
        } 
            else
        {
            printf ("You can enter only numbers and decimal point \".\"! \n");                    
        }    

    }


    float secondFloat = atof (second);

    while (1)
    {
    printf ("Enter the angle in degrees: ");
    fgets (angle, sizeof(angle), stdin);
    angle[strcspn(angle, "\n")] = '\0';  
 

        if (strspn(angle, "0123456789.") == strlen(angle))   
        {                                        
            angleFloat = atof (angle); 
            if (angleFloat >0 &&angleFloat <=360 ) 
            {
                break;
            }
            else
            {
                printf ("You can enter only numbers between 0 and 360! \n"); 
            }     
        } 
            else
        {
            printf ("You can enter only numbers and decimal point \".\"! \n");                    
        }    

    }
    
    // float angleInRadians = angleFloat * (pi / 180); //convert degrees in radians
    // float area = 0.5*firstFloat*secondFloat*sin(angleInRadians); 
    // float perimeter = firstFloat + secondFloat + sqrt(firstFloat * firstFloat + secondFloat * secondFloat - 2 * firstFloat * secondFloat * cos(angleInRadians));
    float perimeter;
    float area = TriangleFormula (firstFloat,  secondFloat,  angleFloat, &perimeter);
    
    printf ("The area of the triangel is %.2f: ", area );
    printf ("\nThe perimeter of the triangel is %.2f: ", perimeter);
    printf ("\nPress any key to continue...\n");
    getch();
   
}

float Circle ()
{   
    const float pi = 3.1415926535;  
    char radius[10000];
    float area;
    float circumference;
    printf("This is Circle!\n");

    while (1)
    {
    printf ("Enter radius: ");
    fgets (radius, sizeof(radius), stdin);
    radius[strcspn(radius, "\n")] = '\0';  


        if (strspn(radius, "0123456789.") == strlen(radius))  //dot is decimal point i C 
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
    float radiusFloat = atof (radius); //convert char to float

    // area = pi*radiusFloat*radiusFloat;
    // circumference = 2*pi*radiusFloat;
    area = CircelFormula (radiusFloat,  &circumference);
    printf ("Area for radius %.2f is %.2f, circumrence is %.2f.\n", radiusFloat, area, circumference);
    printf ("Press any key to continue...\n");
    getch();
}

void Shapes ()
{

    char choice[25];
    char input[1000000]; 
    int choiceInt = 0;


    while(1){
    printf ("\n");
    printf("Menu\n");
    printf("Rectangle\n");
    printf("Parallelogram\n");
    printf("Triangle\n");
    printf("Circle\n");
    printf("Back\n");

    while(1)
    {

        printf ("Enter your choice: ");
        fgets (input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';  //replace last entered symbol ENTER with \0

        for (int i = 0; input[i]; i++) 
        {
        input[i] = tolower(input[i]);  //all entered symbols are in lowcase
        }
            
        if ((strcmp(input, "rectangle") == 0)||
        (strcmp(input, "parallelogram") == 0)|| 
        (strcmp(input, "triangle") == 0)||
        (strcmp(input, "circle") == 0)||
        (strcmp(input, "back") == 0))
        {                          
        printf ("You entered correct! \n");  
        break;
        } 
        else
        {
        printf ("You can enter only certain words! \n");                    
        }     
    }

    //this construction is here to prepare to use switch
    if  (strcmp (input, "rectangle")==0)
        {   
            choiceInt = 1;
        }
        if  (strcmp (input, "parallelogram")==0)
        {     
            choiceInt = 2;            
        }
        if  (strcmp (input,  "triangle")==0)
        {   
            choiceInt = 3;
        }
        if  (strcmp (input, "circle")==0)
        {
            choiceInt = 4;
        }
        if  (strcmp (input,  "back")==0)
        { 
            choiceInt = 5;
        }

        switch (choiceInt)
        {   
        case 1:
            Rectangle();
            break;
        case 2:
            Parallelogram();
            break;
        case 3:
            Triangle();
            break;        
        case 4:
            Circle ();
            break;
        case 5:
            printf ("CASE 5");
            return;
            break;  
        default:
            break;
        }
    }
}
