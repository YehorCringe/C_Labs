#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void shuffleString(char *str) {
    int length = strlen(str);
    srand(time(NULL));

    for (int i = length - 1; i > 0; i--) {
        int j = rand() % (i + 1);

        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    char inputString[100];
    printf("Input a string: ");
    fgets(inputString, sizeof(inputString), stdin);

    inputString[strcspn(inputString, "\n")] = '\0';

    shuffleString(inputString);

    printf("Shuffled string: %s\n", inputString);
}
