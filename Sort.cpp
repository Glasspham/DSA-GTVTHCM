#include<bits/stdc++.h>
using namespace std;
#define ll long long

void Swap(int &a, int &b) {
    int c = a;
    a = b;
    b = a;
}

// Interchange Sort
void InterchangeSort(int a[], int n) {
    for(int i = 0; i < n - 1; ++i)
        for(int j = i + 1; j < n; ++j)
            if(a[i] > a[j])
                Swap(a[i], a[j]);
}

// Selection Sort
void SelectionSort(int a[], int n) {
    for(int i = 0; i < n - 1; ++i) {
        int idx = i;
        for(int j = i + 1; j < n; ++j)
            if(a[idx] > a[j])
                idx = j;
        if(idx != i) Swap(a[i], a[idx]);
    }
}

// Insertion Sort
void InsertionSort(int a[], int n) {
    for(int i = 1; i < n; ++i) {
        int pos = i - 1, x = a[i];
        while(pos > 0 && a[pos] > x) {
            a[pos + 1] = a[pos];
            --pos;
        }
        a[pos + 1] = x;
    }
}

// Bubble Sort
void BubbleSort(int a[], int n) {
    for(int i = 0; i < n - 1; ++i)
        for(int j = n - 1; j > i; --j)
            if(a[j] < a[j - 1])
                Swap(a[j], a[j - 1]);
}

// Quick Sort
void QuickSort(int a[], int left, int right) {
    int pivot = a[(left + right) / 2];
    int i = left, j = right;
    while(i <= j) {
        while(a[i] < pivot) ++i;
        while(a[j] > pivot) --j;
        if(i <= j) Swap(a[i], a[j]);
    }
    if(left < j) QuickSort(a, left, j);
    if(i < right) QuickSort(a, i, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}