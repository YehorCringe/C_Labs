#include <stdio.h>
#include <stdlib.h>

struct Book {
    char title[100];
    float price;
    int pages;
    char language[20];
    float weight;
    int publicationYear;
    struct Book* next;
};


struct Book* addBook(struct Book* head, const char* title, float price, int pages, const char* language, float weight, int publicationYear) {
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    if (newBook == NULL) {
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    snprintf(newBook->title, sizeof(newBook->title), "%s", title);
    newBook->price = price;
    newBook->pages = pages;
    snprintf(newBook->language, sizeof(newBook->language), "%s", language);
    newBook->weight = weight;
    newBook->publicationYear = publicationYear;


    newBook->next = head;
    return newBook;
}


void displayBooks(struct Book* head) {
    struct Book* current = head;

    while (current != NULL) {
        printf("Title: %s\n", current->title);
        printf("Price: %.2f\n", current->price);
        printf("Pages: %d\n", current->pages);
        printf("Language: %s\n", current->language);
        printf("Weight: %.2f\n", current->weight);
        printf("Publication Year: %d\n", current->publicationYear);
        printf("\n");

        current = current->next;
    }
}

void freeBooks(struct Book* head) {
    struct Book* current = head;
    struct Book* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    struct Book* booksList = NULL;


    booksList = addBook(booksList, "Harry Potter and the Philosopher's Stone", 25.99, 336, "English", 0.7, 1997);
    booksList = addBook(booksList, "Harry Potter and the Chamber of Secrets", 27.99, 368, "English", 0.8, 1998);
    booksList = addBook(booksList, "Harry Potter and the Prisoner of Azkaban", 29.99, 448, "English", 0.9, 1999);

    displayBooks(booksList);

    freeBooks(booksList);

}
