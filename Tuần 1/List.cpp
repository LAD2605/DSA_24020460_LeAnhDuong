#include <iostream>

using namespace std;

struct List {
	int *a;
	int cnt = 0;
	int size;
	
	List(int size) : a(new int[size]), size(size) {}
	
	int get(int k) {
		if (k >= 0 && k < cnt) {
			return a[k];
		}
		return -1;
	} 
	
	void insertFirst(int x) {
		if (cnt == size) return;
		for (int i = cnt; i > 0; i--) a[i] = a[i-1];
		a[0] = x;
		cnt++;
	}
	
	void insertLast(int x) {
		if (cnt == size) return;
		a[cnt++] = x;
	}
	
	void insertAt(int k, int x) {
		if ((k > cnt && k < 0) || cnt == size) return;
		for (int i = cnt; i > k; i--) a[i] = a[i-1];
		a[k] = x;
		cnt++;
	}
    
    void deleteFirst() {
        if (cnt == 0) return;
        for (int i = 0; i < cnt - 1; i++) a[i] = a[i + 1];
        cnt--;
    }
	
    void deleteLast() {
        if (cnt == 0) return;
        cnt--;
    }
	
    void traverseForward() {
        for (int i = 0; i < cnt; i++) cout << a[i] << " ";
        cout << endl;
    }
    
    void traverseBackward() {
    	for (int i = cnt - 1; i >= 0; i--) cout << a[i] << " ";
		cout << endl;
	}
};

int main() {
    List a(10);
    
    a.insertFirst(10);
    a.insertFirst(20);
    a.insertFirst(30);
    a.traverseForward();

    a.insertLast(40);
    a.insertLast(50);
    a.traverseForward();
    
    a.insertAt(2, 25);
    a.traverseForward();
    
    cout << a.get(3) << endl;
    a.deleteFirst();
    a.traverseForward();

    a.deleteLast();
    a.traverseForward();
    a.traverseBackward();

    return 0;
}
