#include <iostream>
using namespace std;

const int MAX = 1000;
struct List {
    int a[MAX];
    int size;
};

void init(List &l);
int get(List l, int i);
void insertFirst(List &l, int n);
void insertLast(List &l, int n);
void insertAt(List &l, int i, int n);
void deleteFirst(List &l);
void deleteLast(List &l);
void deleteAt(List &l, int i);
void traverseFor(List l);
void traverseBack(List l);

struct Node {
    int data;
    Node* next;
};
typedef Node* node;

node makeNode(int x);
int Size(node a);
void insertLast(node &a, int x);
void insertFirst(node &a, int x);
void insertAt(node &a, int x, int pos);
void deleteFirst(node &a);
void deleteLast(node &a);
void deleteAt(node &a, int pos);
void traverseFor(node a);
void traverseBack(node a);
int get(node a, int pos);

