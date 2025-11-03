#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int val) : data(val), next(NULL) {}
};

typedef struct Node* node;

struct SLL {
    node head = NULL;
    
    int get(int k) {
        if (head == NULL || k < 0)
            return -1;
        node tmp = head;
        while (k--) {
            tmp = tmp->next;
            if (tmp == NULL)
                return -1;
        }
        return tmp->data;
    }
    
    void insertFirst(int x) {
        node tmp = new Node(x);
        tmp->next = head;
        head = tmp;
    }
    
    void insertLast(int x) {
        node tmp = new Node(x);
        node r = head;
        if (head == NULL) {
            head = tmp;
            return;
        }
        while (r->next != NULL) {
            r = r->next;
        }
        r->next = tmp;
    }
    
    void insertAt(int k, int x) {
        node tmp = new Node(x);
        node r = head;
        while (k--) {
            r = r->next;
            if (r == NULL)
                return;
        }
        tmp->next = r->next;
        r->next = tmp;
    }
    
    void deleteFirst() {
        if (head == NULL)
            return;
        node tmp = head;
        head = head->next;
        delete tmp;
    }
    
    void deleteLast() {
        if (head == NULL)
            return;
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        node tmp = head;
        while (tmp->next->next != NULL) {
            tmp = tmp->next;
        }
        delete tmp->next;
        tmp->next = NULL;
    }

    void deleteAt(int k) {
        if (head == NULL || k < 0)
            return;
        node tmp = head;
        for (int i = 0; i < k - 1; i++) {
            tmp = tmp->next;
        }
        node r = tmp->next;
        tmp->next = r->next;
        delete r;
    }
    
    void traverseForward() {
        node tmp = head;
        while (tmp != NULL) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }
    
    void traverseBackward(node tmp) {
        if (tmp == NULL)
            return;
        traverseBackward(tmp->next);
        cout << tmp->data << " ";
    }
};


int main() {
    SLL a;
    a.insertFirst(10);
    a.insertFirst(20);
    a.insertLast(30);
    a.insertLast(40);
    a.insertAt(1, 100);
    cout << a.get(1) << endl;
    a.traverseForward();
    
    a.deleteFirst();
    a.deleteLast();
    a.deleteAt(1);
    a.traverseForward();
    a.traverseBackward(a.head);
    cout << endl;

    return 0;
}
