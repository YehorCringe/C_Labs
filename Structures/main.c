#include <stdio.h>


typedef int (*func_t)(int, int);

int add(int a, int b) {
    return a + b;
}

int divide(int a, int b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Error: Division by zero\n");
        return 0;
    }
}

int multiply(int a, int b) {
    return a * b;
}

int subtract(int a, int b) {
    return a - b;
}

struct operation_t {
    char operation;
    func_t func;
};

struct operation_t operations[] = {
        {'+', add},
        {'/', divide},
        {'*', multiply},
        {'-', subtract},
};

int main() {
    // Передбачаємо, що масив має щонайменше 2 елементи
    int operand1 = 10;
    int operand2 = 0;

    for (int i = 0; i < sizeof(operations) / sizeof(struct operation_t); i++) {
        char operation = operations[i].operation;
        func_t func = operations[i].func;

        if (!(operation == '/' && operand2 == 0)) {
            printf("%d %c %d = %d\n", operand1, operation, operand2, func(operand1, operand2));
        } else{
            printf("Division by 0\n");
        }
    }
}
