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

    void insertLast(int x) {
        node tmp = new Node(x);
        if (head == NULL) {
            head = tmp;
            return;
        }
        node r = head;
        while (r->next != NULL) {
            r = r->next;
        }
        r->next = tmp;
    }

    int deleteFirst() {
        if (head == NULL)
            return -1;
        node tmp = head;
        int value = tmp->data;
        head = head->next;
        delete tmp;
        return value;
    }

    int getFirst() {
        if (head == NULL)
            return -1;
        return head->data;
    }

    int getSize() {
        int size = 0;
        node tmp = head;
        while (tmp != NULL) {
            size++;
            tmp = tmp->next;
        }
        return size;
    }

    bool isEmpty() {
        return head == NULL;
    }
};

struct QueueLL {
	SLL sll;
    
    QueueLL() {}

    bool isEmpty() {
        return sll.isEmpty();
    }

    void enqueue(int item) {
        sll.insertLast(item); 
    }

    int dequeue() {
        return sll.deleteFirst(); 
    }

    int peek() {
        return sll.getFirst(); 
    }
    
    int getSize() {
        return sll.getSize(); 
    }
};

int main() {
    QueueLL a;
    if (a.isEmpty())
        cout << "Empty" << endl;

    a.enqueue(100);
    a.enqueue(200);

    cout << a.dequeue() << endl; // 100
    cout << a.peek() << endl;    // 200
    cout << a.getSize() << endl; // 1

    return 0;
}
