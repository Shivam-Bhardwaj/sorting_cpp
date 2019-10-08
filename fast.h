//
// Created by shivam on 10/8/19.
//

#ifndef SORT_FAST_H
#define SORT_FAST_H

#include "vector"

class fast {
public:
    void sort(std::vector<int> &, int);
    int partition(std::vector<int> & a, int start, int end);
    void quickSort(std::vector <int> & a, int p, int r);
};


#endif //SORT_FAST_H
