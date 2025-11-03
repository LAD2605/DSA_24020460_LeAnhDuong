#include <iostream>
using namespace std;

struct List {
	int *a;
	int count = 0;
	int size;
	
	List(int size) : a(new int[size]), size(size) {}
	
	int get(int k) {
		if (k >= 0 && k < count) {
			return a[k];
		}
		return -1;
	} 

	void insertFirst(int x) {
		if (count == size) return;
		for (int i = count; i > 0; i--) a[i] = a[i-1];
		a[0] = x;
		count++;
	}

	void insertLast(int x) {
		if (count == size) return;
		a[count++] = x;
	}

	void insertAt(int k, int x) {
		if ((k > count && k< 0) || count == size) return;
		for (int i = count; i > k; i--) a[i] = a[i-1];
		a[k] = x;
		count++;
	}

    void deleteFirst() {
        if (count == 0) return;
        for (int i = 0; i < count - 1; i++) a[i] = a[i + 1];
        count--;
    }

    void deleteLast() {
        if (count == 0) return;
        count--;
    }
	
    void traverseForward() {
        for (int i = 0; i < count; i++) cout << a[i] << " ";
        cout << endl;
    }
    
    void traverseBackward() {
    	for (int i = count - 1; i >= 0; i--) cout << a[i] << " ";
		cout << endl;
	}
};

struct StackList {
    List list;
    
    StackList(int size) : list(size) {}

    bool isEmpty() {
        return list.count == 0;
    }

    void push(int n) {
        list.insertLast(n);
    }

    int pop() {
        return list.get(list.count - 1);
        list.deleteLast();
    }

    int getSize() {
        return list.count;
    }

    int top() {
        if (isEmpty()) return -1;
        return list.get(list.count - 1);
    }
};

int main() {
    StackList a(50);
    a.push(100);
    a.push(200);
    cout << a.pop() << endl;  
    cout << a.top() << endl;   
    cout << a.getSize() << endl; 

    return 0;
}
