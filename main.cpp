#include "iostream"
#include "vector"
#include <algorithm>
#include <bits/stdc++.h>
#include "mSort.h"
#include "utility.h"

using namespace std;

int main() {
    cout << "here";
    int size;
//    cin >> size;
    int n = 0;
    mSort m;
    utility u;
//    vector<int> a;
//    for (int i = 0; i < size; ++i) {
//
//        cin >> n;
//        a.push_back(n);
//    }
//
//    merge_sort(a, size);
//
//    cout<<"\n sorted vector is: "<<endl;
//    vector<int>::iterator itr;
//    for (itr = a.begin(); itr != a.end(); itr++) {
//        cout << *itr << " ";
//    }
    size = 1000000;
    std::vector<int> v(size);
    for (int i = 0; i < 10; ++i) {


        std::generate(v.begin(), v.end(), std::rand);
        time_t start, end;
        time(&start);
        m.merge_sort(v, size);
//        sort(v.begin(), v.end());
        time(&end);
        double time_taken;
        time_taken = double(end - start);
        cout << "Time taken by sort() : " << fixed
             << time_taken;// << setprecision(10);
        cout << " sec " << endl;
        cout << u.sanity(v);


//        std::generate(v.begin(), v.end(), std::rand);
////    time_t start, end;
//        time(&start);
////        merge_sort(v, size);
//        quickSort(v, 0, size-1);
////    sort(v.begin(),v.end());
//        time(&end);
//        time_taken = double(end - start);
//        cout << "\nTime taken by quick sort : " << fixed
//             << time_taken;// << setprecision(10);
//        cout << " sec " << endl;
//        cout << sanity(v)<<endl;
    }


}

void quickSort(vector <int> & a, int p, int r) {
  if (p < r) {
    int q = partition(a, p, r);
    quickSort(a, p, q - 1);
    quickSort(a, q + 1, r);
  }
}

int partition(vector<int> & a, int start, int end) {
  unsigned int pivot = a[start];
  unsigned int from_left = start+1;
  unsigned int from_right = end;
  unsigned int tmp;

  //cout << "Vector entering partition:";
  //print (a,start,end);
  //cout << endl;

  while (from_left != from_right) {
    if (a[from_left]  <= pivot) from_left++;
    else {
      while (( from_left != from_right)  && (pivot < a[from_right])) from_right--;
      //cout << "swaping " << a[from_left] << " with "<< a[from_right] << endl;
      tmp =  a[from_right];
      a[from_right] = a[from_left];
      a[from_left] = tmp;
    }
  }

  if (a[from_left]>pivot) from_left--;
  a[start] = a[from_left];
  a[from_left] = pivot;

  //cout << "Vector after partition:   ";
  //print (a,start,end);
  //cout << endl;

  return (from_left);
}