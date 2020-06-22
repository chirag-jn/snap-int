#include "strings.h"

void scramble(char* str) {
    srand(time(0));
    int i = 0;
    int j = strlen(str)-1;
    int random = rand();
    char temp = ' ';
    int z;

    for(i=j-1; i>-1; i--) {
        z = random%(i+1);
        temp = str[z];
        str[z] = str[i];
        str[i] = temp;
    }
}

void reverse(char* str) {
    int i = 0;
    int j = strlen(str)-1;
    char temp = ' ';

    while(i<j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}