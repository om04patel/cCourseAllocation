#include "header.h"

int main (int argc, char * argv[]){

    struct courseStruct courseInfo [NUMBER_COURSES];

    struct profStruct profInfo [NUMBER_PROFS];

    char profsNCourses [NUMBER_PROFS][MAX_STR];

    int n, userInput;

    int cNumFound,courseNum;

    char cNameFound[MAX_STR];

    char name[MAX_STR];

    char taughtBy[NUMBER_PROFS][MAX_STR];

    int numRead, choice;

    float a;

    openFileForReading(argv[1]); //Calling Function 1
    
    readCourse(argv[1],courseInfo); //Calling Function 2;

    readProfAndCoursesTaught(argv[2],profInfo,courseInfo); //Calling Function 3

    do{                                       //Menu Display with do While loop
        printf ("\nHere is the menu \n\n");
        printf ("4.    Function 4 - Return the total number of professors who teach 'n' or more courses.\n");
        printf ("5.    Function 5 - Search for a course by entering the course ID.\n");
        printf ("6.    Function 6 - Search for a course by entering the course name. \n");
        printf ("7.    Function 7 - Search for the profs who teach a course by entering the course ID.\n");
        printf ("8.    Function 8 - Returns the average number of courses taught by a professor. \n");
        printf ("9.   Enter any number other than (4,5,6,7,8) to Exit\n");
        printf("\n");
        
        printf ("Enter your choice: ");
        numRead = scanf("%d", &choice); 
        printf("\n");
        
        while(numRead != 1){
            scanf("%*[^\n]");
            printf("Invalid Input.");
            printf ("\nHere is the menu \n\n");
            printf ("4.    Function 4 - Return the total number of professors who teach 'n' or more courses.\n");
            printf ("5.    Function 5 - Search for a course by entering the course ID.\n");
            printf ("6.    Function 6 - Search for a course by entering the course name. \n");
            printf ("7.    Function 7 - Search for the profs who teach a course by entering the course ID.\n");
            printf ("8.    Function 8 - Returns the average number of courses taught by a professor. \n");
            printf ("9.    Enter any number other than (4,5,6,7,8) to Exit\n");
            printf("\n");
            printf ("Enter your choice: ");
            numRead = scanf("%d",&choice); 
        }

        switch(choice) {
            case 4:

                printf("Enter a value 'n' to find the amount of professors who teach n or more courses (n>=0): ");
                scanf("%d", &n);

                if(n < 0){
                    printf("Invalid Input");
                    break;
                }
    
                 int x = nCourses(n,profInfo,profsNCourses); //Calling Function 4
                 printf("%d profs teach 'n' or more courses\n",x);

            break;

            case 5:

                printf("Enter the course ID you would like to look for: ");
                scanf("%d", &userInput);

                getCourseName(userInput,cNameFound,courseInfo);
                printf("The corresponding course name is %s\n", cNameFound);
            break;

            case 6:
                        
                getchar();  //Removing \n so we can use fgets
                printf("Enter the course name you would like to look for: ");
                fgets(name, MAX_STR, stdin);

                getCourseNum(name, &cNumFound, courseInfo); //Calling Function 6
                printf("The corresponding course ID is %d\n", cNumFound);
            break;

            case 7:

                printf("Enter the course number: ");
                scanf("%d", &courseNum);
    
                int y = profsTeachingCourse(courseNum,profInfo,taughtBy);
                printf("%d profs teach this course\n",y);
            break;

            case 8:

                a = avgNumCourses(profInfo);
                printf("The average number of courses taught by a professor is %.1lf\n", a);
            break;

            default:

                break;
        }
    }while(choice == 4 || choice == 5 || choice == 6 || choice == 7 || choice == 8);

    return 0;}


