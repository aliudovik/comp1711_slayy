#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "FitnessDataStruct.h"

// Struct moved to header file


// Define any additional variables here
// Global variables for filename and FITNESS_DATA array
char date[11];
char time[6];
char steps[10];
int a;
int i;
char *records[100];
char filename[20];
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



FILE *open_file(char filename[], char mode[]) {
    FILE *file = fopen(filename, mode);
    if (file == NULL) {
        perror("Error: Could not find or open the file.");
        exit(1); // Exits program with return status 1.
    } else {
        printf("File successfully loaded.\n");
    }

    int buffer_size = 100;
    char line_buffer[buffer_size];
    while(fgets(line_buffer, buffer_size, file) != NULL)
    {
        records[i] = malloc(buffer_size);
        strcpy(records[i], line_buffer);
        i++;
    }

    while(a < i){
        tokeniseRecord(records[a], ",", date, time, steps);
        strcpy(record[a].date, date);
        strcpy(record[a].time, time);
        record[a].steps = atoi(steps);
        a++;
    }

    fclose(file);
    return 0;
}


int optionC() {
    int min = record[0].steps;
    int min_index;
    for (int k = 0; k < i; k++)
    {
        if (record[k].steps < min)
        {
            min = record[k].steps;
            min_index = k;
        }
    }
    printf("Fewest steps: %s %s\n", record[min_index].date, record[min_index].time);
    return 0;
}

int optionD() {
    int max = record[0].steps;
    int max_index;
    for (int b = 0; b < i; b++)
    {
        if (record[b].steps > max)
        {
            max = record[b].steps;
            max_index = b;
        }
    }
    printf("Largest steps: %s %s\n", record[max_index].date, record[max_index].time);
    return 0;
}

int optionE() {
    int total = 0;
    float mean_float;
    int mean;
    for (int q = 0; q < i; q++){
        total += record[q].steps;
    }
    mean_float = total / i;
    mean = roundf(mean_float);
    printf("Mean step count: %d\n", mean);
    return 0;
}

int optionF() {
    int d = 0;
    int t = 0;
    char arrFH[100];
    while (t < i){
        if (record[t].steps > 500) {
            arrFH[d] = t;
            d++;
            t++;
        } else {
            t++;
        }
    }
    int longestStart = 0, longestEnd = 0;
    int currentStart = 0, currentEnd = 0;

    for (int y = 1; y < d; y++) {
        if (arrFH[y] - arrFH[y - 1] == 1) {
            currentEnd = y;
        } else {
            currentStart = currentEnd = y;
        }
        if (currentEnd - currentStart > longestEnd - longestStart) {
            longestStart = currentStart;
            longestEnd = currentEnd;
        }
    }
    int j = arrFH[longestStart];
    int l = arrFH[longestEnd];
    // Print the longest arithmetic sequence
    printf("Longest period start: %s, %s\nLongest period end: %s, %s\n", record[j].date, record[j].time, record[l].date, record[l].time);
    return 0;
}


// Complete the main function
int main() {
    char option[1];
    printf("Menu Options:\nA: Specify the filename to be imported\nB: Display the total number of records in the file\nC: Find the date and time of the timeslot with the fewest steps\nD: Find the date and time of the timeslot with the largest number of steps\nE: Find the mean step count of all the records in the file\nF: Find the longest continuous period where the step count is above 500 steps\nQ: Quit\nEnter choice: ");
    scanf("%s", &option);

    if (strcmp(option, "A") == 0) {
        printf("Input filename: ");
        scanf("%s", &filename);
        open_file(filename, "r");
        main();
    } else if (strcmp(option, "B") == 0) {
        printf("Total records: %d\n", i);
        main();
    } else if (strcmp(option, "C") == 0) {
        optionC();
        main();
    } else if (strcmp(option, "D") == 0) {
        optionD();
        main();
    } else if (strcmp(option, "E") == 0) {
        optionE();
        main();
    } else if (strcmp(option, "F") == 0) {
        optionF();
        main();
    } else if (strcmp(option, "Q") == 0) {
        exit(0);
    } else {
        printf("Invalid choice. Try again.\n");
        main();
    }
}














