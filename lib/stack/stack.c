#include "stack.h"
#include <stdlib.h>

Stack stack_new() {
    Stack s = malloc(sizeof(_Stack));
    s->top = NULL;
    s->size = 0;
    return s;
}

void stack_push(Stack s, void *data) {
    Elem e = malloc(sizeof(_Elem));
    e->data = data;
    e->next = s->top;
    s->top = e;
    s->size++;
}

void *stack_pop(Stack s) {
    if (s->size == 0) {
        return NULL;
    }
    Elem e = s->top;
    s->top = e->next;
    s->size--;
    void *data = e->data;
    free(e);
    return data;
}

bool stack_contains(Stack s, void *data) {
    Elem e = s->top;
    while (e != NULL) {
        if (e->data == data) {
            return true;
        }
        e = e->next;
    }
    return false;
}

bool stack_is_empty(Stack s) {
    return s->size == 0;
}

void stack_free(Stack s) {
    while (s->size > 0) {
        stack_pop(s);
    }
    free(s);
}
