//
// Created by shivam on 10/7/19.
//

#ifndef SORT_MSORT_H
#define SORT_MSORT_H

#include "vector"
using namespace std;

class mSort {
public:
    void merge_sort(vector<int> &, int);

    void merge(vector<int> &in1, int n1, vector<int> &in2, int n2, vector<int> &out);
};


#endif //SORT_MSORT_H
