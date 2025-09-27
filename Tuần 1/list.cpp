#include "list.h"

int get(List l, int i) {
    if (i < 0 || i >= l.size) return -1;
    return l.a[i];
}

void insertFirst(List &l, int n) {
    for (int i = l.size; i > 0; i--) {
        l.a[i] = l.a[i-1];
    }
    l.a[0] = n;
    l.size++;
}

void insertLast(List &l, int n) {
    l.a[l.size++] = n;
}

void insertAt(List &l, int i, int n) {
    if (i < 0 || i > l.size) return;
    for (int j = l.size; j > i; j--) {
        l.a[j] = l.a[j-1];
    }
    l.a[i] = n;
    l.size++;
}

void deleteFirst(List &l) {
    if (l.size == 0) return;
    for (int i = 0; i < l.size-1; i++) {
        l.a[i] = l.a[i+1];
    }
    l.size--;
}

void deleteLast(List &l) {
    if (l.size == 0) return;
    l.size--;
}

void deleteAt(List &l, int i) {
    if (i < 0 || i >= l.size) return;
    for (int j = i; j < l.size-1; j++) {
        l.a[j] = l.a[j+1];
    }
    l.size--;
}

void traverseFor(List l) {
    for (int i = 0; i < l.size; i++) {
        cout << l.a[i] << " ";
    }
    cout << endl;
}

void traverseBack(List l) {
    for (int i = l.size-1; i >= 0; i--) {
        cout << l.a[i] << " ";
    }
    cout << endl;
}


