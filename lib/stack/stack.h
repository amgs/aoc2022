#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct Elem _Elem, *Elem;
struct Elem {
    void *data;
    Elem next;
};

typedef struct {
    Elem top;
    int size;
} _Stack, *Stack;

Stack stack_new();

void stack_push(Stack s, void *data);

void *stack_pop(Stack s);

bool stack_contains(Stack s, void *data);

void stack_free(Stack s);

bool stack_is_empty(Stack s);

#endif