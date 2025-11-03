#include <iostream>
#include <string>

using namespace std;

class STList {
private:
    int *data;
    string *key;
    int count;
    int size;

    int binarySearch(string a, int left, int right) {
        if (left > right) 
            return -1;
        int mid = left + (right - left) / 2;
        if (a == key[mid]) 
            return mid;
        if (a < key[mid]) 
            return binarySearch(a, left, mid - 1);
        return binarySearch(a, mid + 1, right);
    }

public:
    STList(int size) : data(new int[size]), key(new string[size]), count(0), size(size) {}

    void put(string a, int value) {
        int pos = binarySearch(a, 0, count - 1);
        if (pos != -1) {
            data[pos] = value;
            return;
        }
        int i;
        for (i = count - 1; (i >= 0 && key[i] > a); --i) {
            data[i + 1] = data[i];
            key[i + 1] = key[i];
        }
        data[i + 1] = value;
        key[i + 1] = a;
        ++count;
    }

    void del(string a) {
        int pos = binarySearch(a, 0, count - 1);
        if (pos != -1) {
            for (int i = pos; i < count - 1; ++i) {
                data[i] = data[i + 1];
                key[i] = key[i + 1];
            }
            --count;
        }
    }

    int get(string a) {
        int pos = binarySearch(a, 0, count - 1);
        return (pos != -1) ? data[pos] : -1;
    }

    bool contains(string a) {
        return binarySearch(a, 0, count - 1) != -1;
    }

    void iterable() {
        for (int i = 0; i < count; i++)
            cout << key[i] << " ";
        cout << endl;
    }

    bool isEmpty() {
        return count == 0;
    }

    int getSize() {
        return count;
    }
};

int main() {
    STList a(10);

    a.put("T", 1);
    a.put("u", 2);
    a.put("n", 3);
    a.put("g", 4);

    cout << a.get("T") << endl;
    cout << a.get("u") << endl;
    a.del("T");
    cout << a.contains("T") << endl;
    cout << a.getSize() << endl;
    a.iterable();

    return 0;
}
