#include "stack_queue.h"

bool isEmpty(Queue q) {
    return q.head == NULL;
}

void enqueue(Queue &q, int x) {
    node tmp = makeNode(x);
    if (q.head == NULL) {
        q.head = q.tail = tmp;
    } else {
        q.tail->next = tmp;
        q.tail = tmp;
    }
    q.count++;
}

int dequeue(Queue &q) {
    if (q.head == NULL) return -1;
    node tmp = q.head;
    int val = tmp->data;
    q.head = q.head->next;
    if (q.head == NULL) q.tail = NULL;
    delete tmp;
    q.count--;
    return val;
}

int front(Queue q) {
    if (isEmpty(q)) return -1;
    return q.head->data;
}

int size(Queue q) {
    return q.count;
}

