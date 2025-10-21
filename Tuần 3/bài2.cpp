#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

void justham(int a[], int &n, int x) {
    a[n++] = x;               
    sort(a, a + n);           

    // trung binh
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    double average = sum / n;

    // trung vi
    double median;
    if (n % 2 == 1)
        median = a[n / 2];
    else
        median = (a[n / 2 - 1] + a[n / 2]) / 2.0;

    cout << fixed << setprecision(1);
    cout << median;
}

int main() {
	
    return 0;
}

