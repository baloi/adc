/* 
 * Testing sprintf formatting....
 */
#include <stdio.h>
#include <stdlib.h>


int main() {
    char *a_name = "The Name";
    char *format_string = "This is %s";
    //TODO: using malloc to allocate, check if format_string with %s should be less...
    long str_size = sizeof(a_name) + sizeof(format_string);
    char *full_string = malloc(str_size);
    //char full_string[255];

    //printf("size of string = %d\n", str_size);

    sprintf(full_string, format_string, a_name);

    printf("full string >>%s<<\n", full_string);

    return 0;
}
