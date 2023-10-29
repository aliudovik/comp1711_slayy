#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here



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
    char filename [] = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("");
        return 1;
    }
    
    int a = 0;
    int record_size = 100;
    char record[record_size];
    while (fgets(record, record_size, file) != NULL) {
        a++;
    //    tokeniseRecord(line_buffer, ",", date, time, steps);
    //    FITNESS_DATA one;
    //    strcpy(one.date, date);
    //    strcpy(one.time, time);
    //    strcpy(one.steps, steps);
    //    printf("%s", one.date);
    }

    //char record[21] = "2023-09-01,07:30,300";
    char date[11];
    char time[6];
    char steps[10];  // Large enough to hold a typical step count as a string

    int stepsint;
    
    tokeniseRecord(record, ",", date, time, steps);
    
    printf("Date: %s\n", date);
    printf("Time: %s\n", time);
    printf("Steps: %s\n", steps);

    struct FITNESS_DATA

    // Convert the steps string to an integer
    stepsint = atoi(steps);
    printf("Steps as an integer: %d\n", stepsint);
    
    printf("Number of records in file: %d\n", a);

    fclose(file);
    return 0;

}
