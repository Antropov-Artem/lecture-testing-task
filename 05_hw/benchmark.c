#include <stdio.h>
#include <time.h> // Для clock()
#include "stack.h"

// Бенчмарк для функции push
void benchmark_push(Stack* stack, int num_operations) {
    clock_t start, end;
    double cpu_time_used;

    start = clock(); // Засекаем время начала
    for (int i = 0; i < num_operations; i++) {
        push(stack, i); // Выполняем push
    }
    end = clock(); // Засекаем время окончания

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Push benchmark: %d operations took %f seconds\n", num_operations, cpu_time_used);
}

// Бенчмарк для функции pop
void benchmark_pop(Stack* stack, int num_operations) {
    clock_t start, end;
    double cpu_time_used;

    // Предварительно заполняем стек
    for (int i = 0; i < num_operations; i++) {
        push(stack, i);
    }

    start = clock(); // Засекаем время начала
    for (int i = 0; i < num_operations; i++) {
        pop(stack); // Выполняем pop
    }
    end = clock(); // Засекаем время окончания

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Pop benchmark: %d operations took %f seconds\n", num_operations, cpu_time_used);
}

int main() {
    Stack stack;
    initStack(&stack);

    int num_operations = 1000000; // Количество операций

    benchmark_push(&stack, num_operations);
    benchmark_pop(&stack, num_operations);

    destroyStack(&stack);
    return 0;
}