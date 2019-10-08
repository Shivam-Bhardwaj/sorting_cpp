#include "iostream"
#include "vector"
#include <algorithm>
#include <bits/stdc++.h>
#include "mSort.h"
#include "utility.h"
#include "qSort.h"

using namespace std;

int main() {
    cout << "Start\n";
    int size;

    int n = 0;
    mSort m;
    qSort q;
    utility u;

//// custom vector check

//    cin >> size;
//    vector<int> a;
//    for (int i = 0; i < size; ++i) {
//
//        cin >> n;
//        a.push_back(n);
//    }
//
//    q.sort(a, size);
//
////    cout<<"\n sorted vector is: "<<endl;
//    u.show(a);
////    cout<<u.sanity(a);
//    cout<<endl;
//    m.merge_sort(a, size);
//    u.show(a);
////    cout<<u.sanity(a);


//// big array check
    size = 20000000;
    std::vector<int> v(size);

    for (int i = 0; i < 10; ++i) {


//// Quick sort
        std::generate(v.begin(), v.end(), std::rand);
        time_t start, end;
        time(&start);
        q.sort(v, size);
        time(&end);
        double time_taken;
        time_taken = double(end - start);
        cout << "Time taken by quick sort() : " << fixed
             << time_taken;// << setprecision(10);
        cout << " sec " << endl;


//// merge sort
//        std::generate(v.begin(), v.end(), std::rand);
//        time(&start);
//        m.merge_sort(v, size);
//        time(&end);
//        time_taken = double(end - start);
//        cout << "Time taken by merge sort() : " << fixed
//             << time_taken;// << setprecision(10);
//        cout << " sec " << endl;

//// STL sort
        std::generate(v.begin(), v.end(), std::rand);
        time(&start);
        sort(v.begin(), v.end());
        time(&end);
        time_taken = double(end - start);
        cout << "Time taken by STL sort() : " << fixed
             << time_taken;// << setprecision(10);
        cout << " sec " << endl << endl;
    }
}



