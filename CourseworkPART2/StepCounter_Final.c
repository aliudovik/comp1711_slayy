#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "FitnessDataStruct.h"

// Struct moved to header file
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array
char date[11];
char time[6];
char steps[10];
int a;
int i;
int k;
char *records[100];
FITNESS_DATA record [100];

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

                    }




// Complete the main function
int main() {
    char option[1];
    printf("Menu Options:\nA: Specify the filename to be imported\nB: Display the total number of records in the file\nC: Find the date and time of the timeslot with the fewest steps\nD: Find the date and time of the timeslot with the largest number of steps\nE: Find the mean step count of all the records in the file\nF: Find the longest continuous period where the step count is above 500 steps\nQ: Quit\nEnter choice: ");
    scanf("%s", option);
    printf("%s", option);

    if (option == "A")
   // Reading the file
    char filename [] = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("");
        return 1;
    }
    
    /* Populating new array "records" with all of the lines from the file:
       (Additional literature was used while completing this step:
       RishabhPrabhu 2018. Dynamic Memory Allocation in C using malloc(), calloc(), free() and realloc(). [Online]. 
       [Accessed 30 October 2023]. Available from: 
       https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/). */
    int buffer_size = 100;
    char line_buffer[buffer_size];
    while(fgets(line_buffer, buffer_size, file) != NULL)
    {
        records[i] = malloc(buffer_size);
        strcpy(records[i], line_buffer);
        i++;
    }

    // Splitting each record and storing it in the appropriate typedef
    while(a < i){
        tokeniseRecord(records[a], ",", date, time, steps);
        strcpy(record[a].date, date);
        strcpy(record[a].time, time);
        record[a].steps = atoi(steps);
        a++;
    }

    // Printing the number of records in the file
    //printf("Number of records in file: %d\n", i);

    // Printing the first three rows
    //while (k < 3) {
    //    printf("%s/%s/%d\n", record[k].date, record[k].time, record[k].steps);
    //    k++;
    //}
    
    // Closing the file
    fclose(file);
    return 0;

}









