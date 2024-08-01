#include "header.h"

FILE *openFileForReading(char fileName [MAX_STR]){  //Function 1

    FILE *fptr = fopen(fileName,"r"); //Open file in read mode

    if (fptr == NULL){    //If file returns NULL 
        return NULL;
    }
    return fptr;    
}

int readCourse (char filename[MAX_STR],struct courseStruct courseInfo [NUMBER_COURSES]){ //Function 2

    FILE * fptr = openFileForReading(filename);  
    FILE * fptr2 = openFileForReading(filename);
    int j = 0;
    int currentLine = 1;
    char forFile;

    if(fptr == NULL){
        return -1;
    }

   do{
        forFile = fgetc(fptr2);
        if (forFile == '\n'){
            currentLine++;
        }
    }while(forFile != EOF);

    if(currentLine != NUMBER_COURSES * 2){   //Error message if currentline does not == NUMBER_COURSES * 2
        return -1;
    }

    for (int i = 0; i < NUMBER_COURSES; i++){   
        fgets(courseInfo[i].courseName, 50, fptr);  //Using for loop and fgets to scan courseNames into the struct
        int x = strlen(courseInfo[i].courseName);
        courseInfo[i].courseName[x - 1] = '\0';    //Terminating the '\n' character caused by the fgets function
    }
    for (int i = 10; i < 20; i++){
        fscanf(fptr,"%d", &courseInfo[j].courseID); //fscanf used to scan the course IDs which are int values
        j++;
    }

      fclose(fptr);
      fclose(fptr2);

    return 1;
}

int readProfAndCoursesTaught (char filename [MAX_STR], struct profStruct profInfo [NUMBER_PROFS], struct courseStruct courseInfo [NUMBER_COURSES]){ //Function 3

   FILE * fptr = openFileForReading(filename); 
    
    char myArray[6][20]; 
    int k = 0;

    if(fptr == NULL){
        return -1;
    }

    for (int i = 0; i < NUMBER_PROFS; i++){
        fscanf(fptr, "%s", profInfo[i].profName);  //fscanf to prof names into profInfo array
    }
    for(int i = 6; i < NUMBER_PROFS * 2; i++){
        fscanf(fptr, "%s", myArray[k]);  //Storing  "ynynyn" string into an array
        for(int j = 0; j < NUMBER_COURSES; j++){
            myArray[k][j] = tolower(myArray[k][j]);
        }
        k++;
    }
    for(int i = 0; i < NUMBER_PROFS; i++){
        for(int j = 0; j < NUMBER_COURSES; j++){
            profInfo[i].coursesTaught[j] = -1;
            if(myArray[i][j] == 'y'){
                profInfo[i].coursesTaught[j] = courseInfo[j].courseID;  //If there is a 'y' in the course, this assigns the course Id to the appropriate prof in courses taught
            }
        }
    }

    fclose(fptr);

    return 1;} 

int nCourses (int n, struct profStruct profInfo [NUMBER_PROFS], char profsNCourses [NUMBER_PROFS][MAX_STR]){ //Function 4
 
    
    int profCounter = 0; //profCounter Variable declared to count the # of profs that teach n or more courses
    int m = 0; //m is a counter variable declared to count the # of courses a prof teaches
    
    for(int i = 0; i < NUMBER_PROFS; i++){  //iterating through the profs and the courses they teach with 2 for loops
        int counter = 0;
        strcpy(profsNCourses[i], "");
        for(int j = 0; j < NUMBER_COURSES; j++){
            if(profInfo[i].coursesTaught[j] != -1){ 
                    counter++; //incrementing counter if the prof teaches a course
                 }
            }
        if(counter >= n){ //Checking if the counter is >= to the n value the user wishes to test
            strcpy(profsNCourses[m],profInfo[i].profName); //copying the profname into profsNCourses array
            profCounter++;
            m++;
        }
    }

    return profCounter;}

int getCourseName (int courseNum, char cNameFound [50], struct courseStruct courseInfo [NUMBER_COURSES]){ //Function 5

    for(int i = 0; i < NUMBER_COURSES; i++){  //iterate through all courses
        if(courseNum == courseInfo[i].courseID){ //check if courseNum matches the courseID for a course
            strcpy(cNameFound, courseInfo[i].courseName); //copy the name of that course to cNameFound array
            return 1;
        }
        else{
            strcpy(cNameFound,"");
        }
    }
    return 0;
}

int getCourseNum (char cName [50], int *cNumFound, struct courseStruct courseInfo [NUMBER_COURSES]){ //Function 6

    cName[strlen(cName) - 1] = '\0'; //terminating '\n' from fgets input

    for(int i = 0; i < NUMBER_COURSES; i++){   //iterating through all courses
        if(strcmp(cName,courseInfo[i].courseName) == 0){ //If the course names match we store the id in *cNumFound 
            *cNumFound = courseInfo[i].courseID;
            return 1;
        }
        else{
            *cNumFound = 0;
        }
    }
    return 0;
}
                
int profsTeachingCourse (int courseNum, struct profStruct profInfo [NUMBER_PROFS], char taughtBy [NUMBER_PROFS][MAX_STR]){ //Function 7

    int counter = 0;

    for(int i = 0; i < NUMBER_PROFS; i++){  //iterating through profs and their courses taught
        strcpy(taughtBy[i],"");
        for(int j = 0; j < NUMBER_COURSES; j++){
            if(courseNum == profInfo[i].coursesTaught[j]){ 
                strcpy(taughtBy[counter], profInfo[i].profName); //If courseNum = a course that is taught by the prof...
                   //we populate the array taughtBy with the names and increment counter
                   counter++;
            }
        }
        
    }
    return counter;
}

float avgNumCourses (struct profStruct profInfo [NUMBER_PROFS]){

    int counter = 0;
    float avg;

    for(int i = 0; i < NUMBER_PROFS; i++){  //iterating through the profs and the courses they teach with 2 for loops
        for(int j = 0; j < NUMBER_COURSES; j++){
            if(profInfo[i].coursesTaught[j] != -1){ 
                    counter++; //incrementing counter if the prof teaches a course
                 }
            }
    }
    avg = (float)counter / NUMBER_PROFS;
    avg = round(avg);
    return avg;
}


