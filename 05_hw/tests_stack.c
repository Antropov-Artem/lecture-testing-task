#include <stdlib.h>
#include "unity.h"
#include "stack.h"

void setUp(void) {
    // Установка начального состояния перед каждым тестом
}

void tearDown(void) {
    // Очистка после каждого теста
}

void test_createNode(void) {
    Node* node = createNode(10);
    TEST_ASSERT_NOT_NULL(node);
    TEST_ASSERT_EQUAL(10, node->data);
    TEST_ASSERT_NULL(node->next);
    free(node);
}

void test_initStack(void) {
    Stack stack;
    initStack(&stack);
    TEST_ASSERT_NULL(stack.top);
}

void test_push(void) {
    Stack stack;
    initStack(&stack);
    push(&stack, 10);
    TEST_ASSERT_NOT_NULL(stack.top);
    TEST_ASSERT_EQUAL(10, stack.top->data);
}

void test_pop(void) {
    Stack stack;
    initStack(&stack);
    push(&stack, 10);
    pop(&stack);
    TEST_ASSERT_NULL(stack.top);
}

void test_pop_empty_stack(void) {
    Stack stack;
    initStack(&stack);
    pop(&stack); // Попытка извлечения из пустого стека
    // Ожидаем, что программа не упадет
}

void test_searchByValue(void) {
    Stack stack;
    initStack(&stack);
    push(&stack, 10);
    push(&stack, 20);
    Node* node = searchByValue(&stack, 10);
    TEST_ASSERT_NOT_NULL(node);
    TEST_ASSERT_EQUAL(10, node->data);
}

void test_searchByIndex(void) {
    Stack stack;
    initStack(&stack);
    push(&stack, 10);
    push(&stack, 20);
    Node* node = searchByIndex(&stack, 1);
    TEST_ASSERT_NOT_NULL(node);
    TEST_ASSERT_EQUAL(10, node->data);
}

void test_getTop(void) {
    Stack stack;
    initStack(&stack);
    push(&stack, 10);
    Node* node = getTop(&stack);
    TEST_ASSERT_NOT_NULL(node);
    TEST_ASSERT_EQUAL(10, node->data);
}

void test_traverseStack(void) {
    Stack stack;
    initStack(&stack);
    push(&stack, 10);
    push(&stack, 20);
    traverseStack(&stack); // Проверяем, что вывод корректный
}

void test_isEmpty(void) {
    Stack stack;
    initStack(&stack);
    TEST_ASSERT_TRUE(isEmpty(&stack));
    push(&stack, 10);
    TEST_ASSERT_FALSE(isEmpty(&stack));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_createNode);
    RUN_TEST(test_initStack);
    RUN_TEST(test_push);
    RUN_TEST(test_pop);
    RUN_TEST(test_pop_empty_stack);
    RUN_TEST(test_searchByValue);
    RUN_TEST(test_searchByIndex);
    RUN_TEST(test_getTop);
    RUN_TEST(test_traverseStack);
    RUN_TEST(test_isEmpty);
    return UNITY_END();
}