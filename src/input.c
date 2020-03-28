#include <stdio.h>
#include "input/input.h"
#include <ctype.h>
#include <stdlib.h>
#include <errno.h>

#define BUFFER_SIZE 64

void clear_spaces(char * str) {
    char count_number = 0;
    for (int i=0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) {
            count_number = 1;
        }
        if (isspace(str[i]) && count_number) {
            str[i] = '\0';
            return;
        }
    }
}

float input_float(FILE * in, FILE * err) {
    char buffer[BUFFER_SIZE];
    char *ptr = buffer;
    float result;
    errno = 0;
    fgets(buffer, BUFFER_SIZE, in);
    clear_spaces(buffer);
    result = strtof(buffer, &ptr);
    if (errno || buffer == ptr || *ptr != 0) {
        fprintf(err, "Error: Incorrect input.\n");
        errno = 1;
    }
    return result;
}
