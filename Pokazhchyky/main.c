#include <stdio.h>

#define MAX_INPUT_LENGTH 512
#define MAX_ENTITY_LENGTH 30

// Функція для вводу рядка
void inputString(char *str) {
    printf("Input sentence: ");
    fgets(str, MAX_INPUT_LENGTH, stdin);

    int length = 0;
    while (str[length] != '\0' && str[length] != '\n') {
        length++;
    }
    if (str[length] == '\n') {
        str[length] = '\0';
    }
}

// Функція для розділення рядка на слова та конструкції перерахування
void parseSentence(const char *sentence) {
    char currentEntity[MAX_ENTITY_LENGTH];
    int isEnumeration = 0;

    for (int i = 0; sentence[i] != '\0'; i++) {
        if (sentence[i] == ':' && sentence[i + 1] == ' ') {
            isEnumeration = 1;
            i += 1;
            continue;
        }

        if (isEnumeration) {
            int j = 0;
            while (sentence[i] != ',' && sentence[i] != ';' && sentence[i] != '\0') {
                currentEntity[j++] = sentence[i++];
            }
            currentEntity[j] = '\0';

            printf("%s\n", currentEntity);

            if (sentence[i] == ',') {
                i++;
            }
            if (sentence[i] == ';') {
                printf("\n");
                i++;
            }
        }
    }
}

int main() {
    char sentence[MAX_INPUT_LENGTH];
    inputString(sentence);
    parseSentence(sentence);
}
