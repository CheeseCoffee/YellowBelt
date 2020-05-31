//
// Created by akbar on 29.04.2020.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end){
    if(range_end-range_begin>=2){
        vector<typename RandomIt::value_type>v1(range_begin,range_begin+(range_end-range_begin)/2);
        vector<typename RandomIt::value_type>v2(range_begin+(range_end-range_begin)/2,range_end);
        MergeSort(begin(v1),end(v1));
        MergeSort(begin(v2),end(v2));
        merge(begin(v1),end(v1),begin(v2),end(v2),range_begin);
    }
};

int main() {
    vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
    MergeSort(begin(v), end(v));
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
