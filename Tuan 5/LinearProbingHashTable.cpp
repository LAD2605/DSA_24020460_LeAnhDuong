#include <iostream>

using namespace std;

struct Node {
    string key;
    int value;

    Node(string k, int val) : key(k), value(val) {}
};

class LinearProbling {
private:
    Node* lp[10000];

    int HashCode(string k) {
        int s = 0;
        for (int i = 0; i < k.length(); i++) {
            s += k[i];
        }
        return s % 100;
    }

public:
    LinearProbling() {
        for (int i = 0; i < 10000; i++) {
            lp[i] = NULL;
        }
    }

    void put(string k, int val) {
        int tmp = HashCode(k);
        while (lp[tmp] != NULL) {
            if (lp[tmp]->key == "\0" || lp[tmp]->key == k) {
                break;
            } else {
                tmp++;
            }
        }
        if (lp[tmp] == NULL) {
            lp[tmp] = new Node(k, val);
        } else {
            lp[tmp]->key = k;
            lp[tmp]->value = val;
        }
    }

    int get(string k) {
        int tmp = HashCode(k);
        while (lp[tmp] != NULL) {
            if (lp[tmp]->key == k) {
                return lp[tmp]->value;
            }
            tmp++;
        }
        return -1;
    }

    void del(string k) {
        int tmp = HashCode(k);
        while (lp[tmp] != NULL) {
            if (lp[tmp]->key == k) {
                break;
            } else {
                tmp++;
            }
        }
        if (lp[tmp] == NULL) {
            return;
        }
        lp[tmp]->key = "\0";
    }
};

int main() {
    LinearProbling a;
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
