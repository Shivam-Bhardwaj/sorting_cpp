//
// Created by shivam on 10/7/19.
//

#include "mSort.h"

void mSort::merge_sort(vector<int> &a, int size) {

    if (size == 0 || size == 1) return;
    int m = size / 2;
    vector<int> t1;
    vector<int> t2;
    for (int i = 0; i < m; ++i) {
        t1.push_back(a[i]);
    }
    for (int j = m; j < size; ++j) {
        t2.push_back(a[j]);
    }
    merge_sort(t1, m);
    merge_sort(t2, size - m);
    merge(t1, m, t2, size - m, a);
}

void mSort::merge(vector<int> &in1, int n1, vector<int> &in2, int n2, vector<int> &out) {
    int t = n1 + n2;

    int i, j, k;
    i = k = j = 0;
    while (i < n1 && j < n2) {
        if (in1[i] < in2[j]) {
            out[k] = in1[i];
            i++;
            k++;
        } else {
            out[k] = in2[j];
            j++;
            k++;
        }
    }

    while (i < n1) {
        out[k] = in1[i];
        i++;
        k++;
    }
    while (j < n2) {
        out[k] = in2[j];
        j++;
        k++;
    }
}