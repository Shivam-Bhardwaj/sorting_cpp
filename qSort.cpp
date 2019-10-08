//
// Created by shivam on 10/7/19.
//

#include "qSort.h"

using namespace std;

inline void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(vector<int> &v, int si, int ei) {
    int count = 0;
    int temp;
    for (int i = si + 1; i < ei + 1; ++i) {
        if (v[si] >= v[i]) count++;
    }

    swap(&v[si], &v[si + count]);
    int pivot_index = si + count;
    int i = si;
    int j = ei;
    while (i < pivot_index && j > pivot_index) {
        if (v[pivot_index] >= v[i]) {
            i++;
        } else if (v[pivot_index] < v[j]) {
            j--;
        } else {
            swap(&v[i], &v[j]);
            i++;
            j--;
        }

    }
    return pivot_index;
}


void recursion(vector<int> &v, int si, int ei) {
    if (si >= ei) return;
    int p = partition(v, si, ei);
    recursion(v, si, p - 1);
    recursion(v, p + 1, ei);

}

void qSort::sort(std::vector<int> &v, int size) {
    recursion(v, 0, size - 1);
}
