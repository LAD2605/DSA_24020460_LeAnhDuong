#include "list.h"

node makeNode(int x) {
    node tmp = new Node;
    tmp->data = x;
    tmp->next = NULL;
    return tmp;
}

int Size(node a) {
    int cnt = 0;
    while (a != NULL) {
        cnt++;
        a = a->next;
    }
    return cnt;
}

void insertFirst(node &a, int x) {
    node tmp = makeNode(x);
    if (a == NULL) {
        a = tmp;
    } else {
        tmp->next = a;
        a = tmp;
    }
}

void insertLast(node &a, int x) {
    node tmp = makeNode(x);
    if (a == NULL) {
        a = tmp;
    } else {
        node p = a;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = tmp;
    }
}

void insertAt(node &a, int x, int pos) {
    int n = Size(a);
    if (pos <= 0 || pos > n + 1) {
        cout << "Vi tri chen khong hop le\n";
        return;
    }
    if (pos == 1) {
        insertFirst(a, x);
        return;
    }
    if (pos == n + 1) {
        insertLast(a, x);
        return;
    }
    node p = a;
    for (int i = 1; i < pos - 1; i++) {
        p = p->next;
    }
    node tmp = makeNode(x);
    tmp->next = p->next;
    p->next = tmp;
}

void deleteFirst(node &a) {
    if (a == NULL) return;
    node tmp = a;
    a = a->next;
    delete tmp;
}

void deleteLast(node &a) {
    if (a == NULL) return;
    node truoc = NULL, sau = a;
    while (sau->next != NULL) {
        truoc = sau;
        sau = sau->next;
    }
    if (truoc == NULL) {
        a = NULL;
    } else {
        truoc->next = NULL;
    }
    delete sau;
}

void deleteAt(node &a, int pos) {
    if (pos <= 0 || pos > Size(a)) return;
    node truoc = NULL, sau = a;
    for (int i = 1; i < pos; i++) {
        truoc = sau;
        sau = sau->next;
    }
    if (truoc == NULL) {
        a = a->next;
    } else {
        truoc->next = sau->next;
    }
    delete sau;
}

void traverseFor(node a) {
    while (a != NULL) {
        cout << a->data << " ";
        a = a->next;
    }
    cout << endl;
}

void traverseBack(node a) {
    if (a == NULL) return;
    traverseBack(a->next);
    cout << a->data << " ";
}

int get(node a, int pos) {
    int i = 1;
    while (a != NULL) {
        if (i == pos) return a->data;
        a = a->next;
        i++;
    }
    return -1;
}


