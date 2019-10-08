//
// Created by shivam on 10/7/19.
//

#include "utility.h"
#include "vector"
#include "iostream"
#include "string"
#include "algorithm"

using namespace std;

bool utility::sanity(std::vector<int> a) {
    int n = a.size();
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1]) {cout<<"sorting failed\n"; return false;}
    }
    cout<<"sorting successful\n";
    return true;
}

void utility::swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int choice() {

    cout<<"\nEnter the type of search algo: \n";
    cout<<"1. Merge Sort\n";
    cout<<"2. Quick Sort\n";
    cout<<"3. Bubble sort\n";
    cout<<"4. Selection sort\n";
    cout<<"enter the option: ";
    int a;
    cin >> a;
    return a;

}

vector<int> vector_return(int o = 1) {

    if (o == 0) {
        int size, n;
        cout << "Enter the number of elements: ";
        cin >> size;
        vector<int> v;
        for (int i = 0; i < size; ++i) {
            cin >> n;
            v.push_back(n);
        }
        return v;
    }else{
        int size = 1000000;
        std::vector<int> v(size);
        std::generate(v.begin(), v.end(), std::rand);
        return v;
    }
}

//void type(){
//    switch(choice()){
//        case 1:{-
//            break;
//        }
//        case 2:{
//            break;
//        }
//        case 3:{
//            break;
//        }
//        case 4:{
//            break;
//        }
//    }
//}
void utility::show(std::vector<int> a) {
    vector<int>::iterator itr;
    for (itr = a.begin(); itr != a.end(); itr++) {
        cout << *itr << " ";
    }
}