#include "strings.h"

int main(int argc, char *argv[]) {
    char str[100];
    char *str2;

    printf("Enter string: ");

    scanf("%s", str);

    str2 = malloc(strlen(str)+1);
    strcpy(str2, str);

    scramble(str);
    reverse(str2);

    printf("Scrambled String: %s\n", str);

    printf("Reversed String: %s\n", str2);

    return 0;
}
