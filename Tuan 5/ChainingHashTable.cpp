#include <iostream>

using namespace std;

struct Node {
    string key;
    int value;
    Node *next;

    Node(string k, int val) : key(k), value(val), next(NULL) {};
};

typedef struct Node *node;

class HashTable {
private:
    node HT[1000];

    int HashCode(string k) {
        int s = 0;
        for (int i = 0; i < k.length(); i++) {
            s = s + k[i];
        }
        return s % 100;
    }

public:
    HashTable() {
        for (int i = 0; i < 100; i++) {
            HT[i] = NULL;
        }
    }
    void put(string k, int val) {
        int tmp = HashCode(k);
        node x = new Node(k, val);
        if (HT[tmp] == NULL) {
            HT[tmp] = x;
            return;
        }
        node y = HT[tmp];
        while (y->next != NULL) {
            if (y->key == k) {
                y->value = val;
                return;
            }
            y = y->next;
        }
        y->next = x;
    }

    int get(string k) {
        int tmp = HashCode(k);
        node x = HT[tmp];
        while (x != NULL) {
            if (x->key == k)
                return x->value;
            x = x->next;
        }
        return -1;
    }

    void del(string k) {
        int tmp = HashCode(k);
        if (HT[tmp] == NULL)
            return;
        if (HT[tmp]->next == NULL) {
            if (HT[tmp]->key == k)
                HT[tmp] = NULL;
            return;
        }
        node x = HT[tmp], y = HT[tmp];
        while (y->key != k) {
            if (y->next == NULL)
                return;
            y = y->next;
            if (x != HT[tmp])
                x = x->next;
        }
        x->next = y->next;
        y->next = NULL;
    }
};

int main()
{
    HashTable a;
    a.put("Le", 15);
    a.put("Anh", 20);
    a.put("Duong", 25);
    a.put("Aisss", 30);

    cout << a.get("Anh") << endl;
    a.del("Anh");
    cout << a.get("Duong") << endl;
    a.del("Aiss");
	return 0;
}
