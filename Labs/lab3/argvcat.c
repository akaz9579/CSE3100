#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* print out an error message and exit */
void my_error(char *s)
{
    perror(s);
    exit(1);
}

/* Concatnate two strings.
 * Dynamically allocate space for the result.
 * Return the address of the result.
 */
char *my_strcat(char *s1, char *s2){
    // TODO 
    char *out = malloc(strlen(s1) + strlen(s2) + 1);


    if (out == NULL)
    {
        my_error("Memory issue");
        return NULL;
    }

    strcpy(out, s1);
    strcat(out,s2);


    return out;
    
}

int main(int argc, char *argv[])
{
    char    *s;

    s = my_strcat("", argv[0]);

    for (int i = 1; i < argc; i ++) {
        char *old = s;
        s = my_strcat(s, argv[i]);
        free(old);
    }
    printf("%s\n", s);
    free(s);

    return 0;
}
