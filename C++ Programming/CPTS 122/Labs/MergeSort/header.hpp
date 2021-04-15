#include <iostream>
#include <time.h>
#define size 25

using namespace std;

template <class t>
class MergeSort {
public:
	void sort(t* arr, int l, int r);
    void merge(t* arr, int l, int m, int r);
	t* arr = new t[size];
};

template <class t>
void MergeSort<t>::sort(t* arr, int l, int r) {
    int m = 0;
    if (l < r) {
        int m = l + (r - l) / 2;
        sort(arr, l, m);
        sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

template <class t>
void MergeSort<t>::merge(t* arr, int l, int m, int r) {
    int i = 0, j = 0, k = 0, nl = 0, n2 = 0;

    nl = m - l + 1; 
    n2 = r - m;
    t* left = new t[nl], *right = new t[n2];

    for (i = 0; i < nl; i++)
        left[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];

    i = 0; 
    j = 0; 
    k = l;

    while (i < nl && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < nl) {
        arr[k] = left[i];
        i++; 
        k++;
    }
    while (j < n2) {
        arr[k] = right[j];
        j++; 
        k++;
    }
}