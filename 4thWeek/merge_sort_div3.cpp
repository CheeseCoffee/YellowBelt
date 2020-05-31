//
// Created by akbar on 30.05.2020.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end){
    int range_len=range_end-range_begin;
    if(range_len>=3){
        vector<typename RandomIt::value_type>v1(range_begin,range_end);
        auto one_third=begin(v1)+range_len/3;
        auto two_third=begin(v1)+range_len*2/3;
        MergeSort(begin(v1),one_third);
        MergeSort(one_third,two_third);
        MergeSort(two_third,end(v1));
        vector<typename RandomIt::value_type>v;
        merge(begin(v1),one_third,one_third,two_third,back_inserter(v));
        merge(begin(v),end(v),two_third,end(v1),range_begin);
    }
};

int main() {
    vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
    MergeSort(begin(v), end(v));
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
