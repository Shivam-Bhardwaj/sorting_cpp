//
// Created by shivam on 10/8/19.
//

#include "fast.h"
#include "vector"
using namespace std;

int fast::partition(vector<int> & a, int start, int end) {
    unsigned int pivot = a[start];
    unsigned int from_left = start+1;
    unsigned int from_right = end;
    unsigned int tmp;

    while (from_left != from_right) {
        if (a[from_left]  <= pivot) from_left++;
        else {
            while (( from_left != from_right)  && (pivot < a[from_right])) from_right--;
            tmp =  a[from_right];
            a[from_right] = a[from_left];
            a[from_left] = tmp;
        }
    }

    if (a[from_left]>pivot) from_left--;
    a[start] = a[from_left];
    a[from_left] = pivot;
    return (from_left);
}

/*
  Recursive QS function. Base case is an empty vector.
  Precondition:
  Postcondition: The vector that was passed as parameter will be
    sorted in ascending order.
*/
void fast::quickSort(vector <int> & a, int p, int r) {
    if (p < r) {
        int q = partition(a, p, r);
        quickSort(a, p, q - 1);
        quickSort(a, q + 1, r);
    }
}

void fast::sort(std::vector<int> & v, int size) {
    quickSort(v, 0, size -1);
}