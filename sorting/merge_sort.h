#ifndef MERGE_SORT
#define MERGE_SORT

#include "iostream"
#include "custom_lib.h"

using namespace std;


template <typename T>
vector<T> merge(vector<T> leftArr, vector<T> rightArr) {
    vector<T> newArr;
    int i, j;
    i = j = 0;
    
    while(i<leftArr.size() && j<rightArr.size()) {
        if (leftArr[i] < rightArr[j]) {
            newArr.push_back(leftArr[i]);
            ++i;
        } else {
            newArr.push_back(rightArr[j]);
            ++j;
        }
    }
    
    while (i<leftArr.size()) {
        newArr.push_back(leftArr[i]);
        ++i;
    }
    while (j<rightArr.size()) {
        newArr.push_back(rightArr[j]);
        ++j;
    }

    return newArr;
}

template <typename T>
vector<T> merge_sort(vector<T> arr) {
    vector<T> leftArr, rightArr;
    int s, e, mid;
    s = 0, e = arr.size()-1, mid = (s+e)/2;
    
    if (arr.size() > 2) {
        for(int i=s; i<mid; ++i)
            leftArr.push_back(arr[i]);
        for(int i=mid; i<=e; ++i)
            rightArr.push_back(arr[i]);        
            
        leftArr = merge_sort(leftArr);
        rightArr = merge_sort(rightArr);
        
    } else if (arr.size() == 2) {
        if (arr[0] > arr[1]) {
            int temp = arr[0];
            arr[0] = arr[1];
            arr[1] = temp;
        }
        return arr;    
        
    } else {
        return arr;
    }

    return merge(leftArr, rightArr);
}

#endif