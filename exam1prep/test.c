#include <stdio.h>      // I/O: printf, scanf, etc.
#include <stdlib.h>     // malloc, free, exit, system, etc.
#include <string.h>     // strlen, strcpy, strcmp, etc.
#include <stdbool.h>    // bool, true, false
#include <ctype.h>      // isalpha, isdigit, tolower, etc.


int main(){
    char *words[3] = {"hi", "bye", "ok"};
    printf("%s %s\n", words[0], *(words+2));
}