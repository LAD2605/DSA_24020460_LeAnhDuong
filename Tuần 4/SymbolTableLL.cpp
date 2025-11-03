#include <iostream>

using namespace std;

struct Node {
    string key;
    int value;
    Node *next;

    Node(string k, int val) : key(k), value(val), next(NULL) {}
};

typedef Node *point;

struct SymbolTable {
    point head;

    SymbolTable() : head(NULL) {}

    void put(string k, int val) {
        if (head == NULL) {
            head = new Node(k, val); 
            return;
        }
        point p = head;
        while (p->next != NULL) {
            if (p->key == k) {
                p->value = val;
                return;
            }
            p = p->next;
        }
        if (p->key == k) {
            p->value = val;
        } else {
            p->next = new Node(k, val); 
        }
    }

    int get(string k) {
        point p = head;
        while (p != NULL) {
            if (p->key == k) {
                return p->value; 
            }
            p = p->next;
        }
        return -1;
    }

    bool contains(string k) {
        point p = head;
        while (p != NULL) {
            if (p->key == k) {
                return true; 
            }
            p = p->next;
        }
        return false;
    }

    bool isEmpty() {
        return head == NULL; 
    }

    int size() {
        point p = head;
        int count = 0;
        while (p != NULL) {
            count++;
            p = p->next;
        }
        return count;
    }

    void del(string k) {
        if (head == NULL) return; 

        if (head->key == k) {
            point temp = head;
            head = head->next;
            delete temp;
            return;
        }

        point p = head;
        while (p->next != NULL && p->next->key != k) {
            p = p->next;
        }
        if (p->next != NULL) {
            point temp = p->next;
            p->next = temp->next;
            delete temp;
        }
    }
};

int main() {
    SymbolTable a;

    a.put("T", 1);
    a.put("u", 2);
    a.put("n", 3);
    a.put("g", 4);

    cout << a.get("T") << endl;
    cout << a.get("u") << endl;

    a.del("T");
    cout << a.contains("T") << endl;
    cout << a.size() << endl;

    return 0;
}
