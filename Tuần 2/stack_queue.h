#include "list.h"

struct Stack {
    List l; // dùng list
};

bool isEmpty(Stack s);
void push(Stack &s, int x);
int pop(Stack &s);
int top(Stack s);
int size(Stack s);

struct Queue {
    node head, tail;  // dùng linked list + tail
    int count;            
    Queue() : head(NULL), tail(NULL), count(0) {}
};

bool isEmpty(Queue q);
void enqueue(Queue &q, int x);
int dequeue(Queue &q);
int front(Queue q);
int size(Queue q);

