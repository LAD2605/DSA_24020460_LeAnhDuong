#include <iostream>
using namespace std;

class PriorityQueue {
private:
    static const int MAX = 1000;
    int a[MAX];  
    int size;    

    void swap(int &x, int &y) {
        int tmp = x;
        x = y;
        y = tmp;
    }

    void swim(int k) {
        while (k > 1 && a[k / 2] < a[k]) {
            swap(a[k], a[k / 2]);
            k /= 2;
        }
    }

    void sink(int k) {
        while (2 * k <= size) {
            int j = 2 * k;
            if (j < size && a[j] < a[j + 1]) j++;
            if (a[k] >= a[j]) break;
            swap(a[k], a[j]);
            k = j;
        }
    }

public:
    PriorityQueue() : size(0) {}

    bool isEmpty() const { return size == 0; }
    int getSize() const { return size; }

    void insert(int val) {
        if (size >= MAX - 1) {
            cout << "Heap full!\n";
            return;
        }
        a[++size] = val;
        swim(size);
    }

    int delMax() {
        if (isEmpty()) return -1;
        int maxVal = a[1];
        swap(a[1], a[size--]);
        sink(1);
        return maxVal;
    }

    int max() const {
        if (isEmpty()) return -1;
        return a[1];
    }

    void clear() { size = 0; }

};

// Demo
int main() {
    PriorityQueue pq;

    pq.insert(40);
    pq.insert(10);
    pq.insert(60);
    pq.insert(30);
    pq.insert(50);

    cout << pq.max() << endl;
    cout << pq.delMax() << endl;

    pq.insert(70);
    pq.insert(20);

    cout << pq.getSize() << endl;

    pq.clear();
}

