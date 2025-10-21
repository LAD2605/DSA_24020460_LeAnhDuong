#include "priority_queue_heap.h"
#include <iostream>
using namespace std;

void swap(int &x, int &y) {
    int tmp = x; x = y; y = tmp;
}

void swim(PriorityQueue &pq, int k) {
    while (k > 1 && pq.a[k/2] < pq.a[k]) {
        swap(pq.a[k], pq.a[k/2]);
        k /= 2;
    }
}

void sink(PriorityQueue &pq, int k) {
    while (2 * k <= pq.size) {
        int j = 2 * k;
        if (j < pq.size && pq.a[j] < pq.a[j + 1]) j++;
        if (pq.a[k] >= pq.a[j]) break;
        swap(pq.a[k], pq.a[j]);
        k = j;
    }
}

void insert(PriorityQueue &pq, int value) {
    if (pq.size == MAX - 1) {
        cout << "Heap day!\n";
        return;
    }
    pq.a[++pq.size] = value;
    swim(pq, pq.size);
}

int delMax(PriorityQueue &pq) {
    if (pq.size == 0) return -1;
    int maxVal = pq.a[1];
    swap(pq.a[1], pq.a[pq.size]);
    pq.size--;
    sink(pq, 1);
    return maxVal;
}

int max(PriorityQueue pq) {
    if (pq.size == 0) return -1;
    return pq.a[1];
}

bool isEmpty(PriorityQueue pq) {
    return pq.size == 0;
}

int size(PriorityQueue pq) {
    return pq.size;
}


