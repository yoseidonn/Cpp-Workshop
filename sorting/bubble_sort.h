#ifndef BUBBLE_SORT
#define BUBBLE_SORT

#include "iostream"
#include "vector"

using namespace std;

template <typename T>
void bubble_sort(vector<T>& arr) {
    int temp, largest_ind;
    
    for(int i = 0; i<arr.size(); ++i) {
        largest_ind = arr.size() - i - 1;
        
        for(int j = 0; j<arr.size()-i; ++j) {
            if (arr[j] > arr[largest_ind]) {
                largest_ind = j;
            }
            
            if (j==arr.size()-i-1) {
                temp = arr[j];
                arr[j] = arr[largest_ind];
                arr[largest_ind] = temp;
            }
        }
    }
}
#endif