const int MAX = 1000;

struct PriorityQueue {
    int a[MAX];
    int size;
    PriorityQueue() : size(0) {}
};

void swim(PriorityQueue &pq, int k);
void sink(PriorityQueue &pq, int k);

void insert(PriorityQueue &pq, int value);
int delMax(PriorityQueue &pq);
int max(PriorityQueue pq);
bool isEmpty(PriorityQueue pq);
int size(PriorityQueue pq);

