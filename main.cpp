#include "iostream"
#include "vector"
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

void merge_sort(vector<int> &, int);

void merge(vector<int> &in1, int n1, vector<int> &in2, int n2, vector<int> &out);

bool sanity(vector<int>);

void swap(int *a, int *b);

int partition(vector<int> & a, int start, int end);

void quickSort(vector <int> & a, int p, int r);

int main() {
    cout << "here";
    int size;
//    cin >> size;
    int n = 0;
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
    size = 100000000;
    std::vector<int> v(size);
    for (int i = 0; i < 10; ++i) {


        std::generate(v.begin(), v.end(), std::rand);
        time_t start, end;
        time(&start);
//    merge_sort(v, size);
        sort(v.begin(), v.end());
        time(&end);
        double time_taken;
        time_taken = double(end - start);
        cout << "Time taken by sort() : " << fixed
             << time_taken;// << setprecision(10);
        cout << " sec " << endl;
        cout << sanity(v);


        std::generate(v.begin(), v.end(), std::rand);
//    time_t start, end;
        time(&start);
//        merge_sort(v, size);
        quickSort(v, 0, size-1);
//    sort(v.begin(),v.end());
        time(&end);
        time_taken = double(end - start);
        cout << "\nTime taken by quick sort : " << fixed
             << time_taken;// << setprecision(10);
        cout << " sec " << endl;
        cout << sanity(v)<<endl;
    }


}

void merge_sort(vector<int> &a, int size) {
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

void merge(vector<int> &in1, int n1, vector<int> &in2, int n2, vector<int> &out) {
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

bool sanity(vector<int> a) {
    cout<<"\n checking sanity : ";
    int n = a.size();
    for (int i = 0; i < n-1; ++i) {
        if(a[i]>a[i+1]) return false;
    }
    return true;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
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