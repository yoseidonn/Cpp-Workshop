#ifndef BINARY_SEARCH
#define BINARY_SEARCH

#include "iostream"
#include "vector"

using namespace std;

template <typename T>
int binary_search(vector<T> arr, T target){
    int i = 0, j = arr.size()-1;

    while (i<=j) {
        int mid = (i+j) / 2; 
        if (target == arr[mid]) {
            return mid;
        }
        else if (target < arr[mid]) {
            j = mid - 1;
        } else {
            i = mid + 1;
        }
    }
    return -1;
}

#endif