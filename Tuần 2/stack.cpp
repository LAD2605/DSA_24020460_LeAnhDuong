#include "stack_queue.h"

bool isEmpty(Stack s) {
    return s.l.size == 0;
}

void push(Stack &s, int x) {
    insertLast(s.l, x);
}

int pop(Stack &s) {
    if (isEmpty(s)) return -1;  
    int val = get(s.l, s.l.size - 1);
    deleteLast(s.l);
    return val;
}

int top(Stack s) {
    if (isEmpty(s)) return -1;
    return get(s.l, s.l.size - 1);
}

int size(Stack s) {
    return s.l.size;
}

