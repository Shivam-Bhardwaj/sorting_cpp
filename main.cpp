#include "iostream"
#include "vector"
#include <algorithm>
#include <bits/stdc++.h>
#include "mSort.h"
#include "utility.h"
#include "qSort.h"
#include "fast.h"
#include "chrono"

#define TEST_TIMES 1
#define N 5000000

using namespace std;
using namespace std::chrono;

int main() {
    cout << "Start\n";
    int size;

    int n = 0;
    mSort m;
    qSort q;
    utility u;
    fast f;

//// custom vector check

//    cin >> size;
//    vector<int> a;
//    for (int i = 0; i < size; ++i) {
//
//        cin >> n;
//        a.push_back(n);
//    }
//    q.sort(a, size);
//    cout<<"\n sorted vector is: "<<endl;
//    u.show(a);
//    cout<<u.sanity(a);
//    cout<<endl;
//    m.merge_sort(a, size);
//    u.show(a);
//    cout<<u.sanity(a);


//// big array check
    size = N;
    std::vector<int> v(size);

    for (int i = 0; i < TEST_TIMES; ++i) {
        cout<<"try "<<i+1<<endl;

//// Quick sort
        {
        std::generate(v.begin(), v.end(), std::rand);
        auto start = high_resolution_clock::now();
        q.sort(v, size);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Time taken by my quick sort: "
             << duration.count()/1000 << " ms" << endl;
//      u.sanity(v);
        }



//// merge sort
//        {
//            std::generate(v.begin(), v.end(), std::rand);
//            auto start = high_resolution_clock::now();
//            m.merge_sort(v, size);
//            auto stop = high_resolution_clock::now();
//            auto duration = duration_cast<microseconds>(stop - start);
//            cout << "Time taken by merge sort: "
//                 << duration.count()/1000 << " ms" << endl;
////      u.sanity(v);
//        }

////// STL sort
        {
            std::generate(v.begin(), v.end(), std::rand);
            auto start = high_resolution_clock::now();
            sort(v.begin(),v.end());
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            cout << "Time taken by STL's sort: "
                 << duration.count()/1000 << " ms" << endl;
//      u.sanity(v);
        }

////// fast sort
        {
            std::generate(v.begin(), v.end(), std::rand);
            auto start = high_resolution_clock::now();
            sort(v.begin(),v.end());
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            cout << "Time taken by fast quick sort: "
                 << duration.count()/1000 << " ms" << endl;
//      u.sanity(v);
        }

        cout<<"test : "<< i+1<< " done\n\n";
    }
}



