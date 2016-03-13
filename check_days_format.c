/* Checks of registrant's scheduled
   days are in correct format in records 
   Possible formats:
   M----
   -T---
   --W--
   ---T-
   ----F
   M-W-F
   MT---
   
   or:
   1 scheduled days should have 5 characters
   2 first character should be 'M' or '-'......
*/
#include <stdio.h>
#include <stdlib.h>

#define REGISTRANT_LIST "registrants.txt"

int adc_getnumrecs(FILE *records, long size);
int adc_getnumlines(FILE *records, long size);
void adc_getrecords(char *records, FILE *fp);

int main() {

    FILE *fp = fopen(REGISTRANT_LIST, "r");
    char *buff;
    long s;
    int nrecs;
    char *records;
    
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    fseek(fp, 0L, SEEK_END);
    s = ftell(fp);
    rewind(fp);
        
    buff = malloc(s);

    if (buff != NULL) {
        fread(buff, s, 1, fp);
        fwrite(buff, s, 1, stdout);
    }

    //printf("\nSize of file = %d\n", s);
    //printf("\nSize of buff = %d\n", sizeof(buff));
    rewind(fp);
    nrecs = adc_getnumrecs(fp, s);

    printf("\n\nnumber of records = %d \n", nrecs);
    
    
    records = malloc(nrecs);

    adc_getrecords(records, fp); 

    free(records);
    free(buff);

    if (fclose(fp) != 0) {
        printf("Error closing file\n");
        return 1;
    }

    return 0;
}

void adc_getrecords(char *records, FILE *fp) {

}

int adc_getnumrecs(FILE *records, long size) {
    int nlines;

    nlines = adc_getnumlines(records, size);
     
    // read through records and count number of lines
    // which should be delimited by '\n'
    return nlines;
}

int adc_getnumlines(FILE *records, long size) {
    int c, i, n;
    n = 0;
    
    for (i = 0; i < size-1 && (c = getc(records)) != EOF; i++) {
        if (c == '\n') {
            n = n + 1;
            //printf("\nCounting %d\n", n);
        }
    } 
    if (n != 0)
        n = n + 1;
    else if (n == 0 && size != 0)
        n = n + 1;

    return n;
}
