//
// Created by shivam on 10/7/19.
//

#include "utility.h"
#include "vector"
#include "iostream"

bool utility::sanity(std::vector<int> a) {
    std::cout<<"\n checking sanity : ";
    int n = a.size();
    for (int i = 0; i < n-1; ++i) {
        if(a[i]>a[i+1]) return false;
    }
    return true;
}

void utility::swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}