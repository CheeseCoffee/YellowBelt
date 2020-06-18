//
// Created by Akbar on 16.06.2020.
//

#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
set<int>::const_iterator FindNearestElement(const set<int>& numbers, int border){
    const auto lower=numbers.lower_bound(border);
    if(lower==numbers.begin()){
        return lower;
    }
    const auto prev_lower=prev(lower);
    if(lower==numbers.end()){
        return prev_lower;
    }
    const bool is_left=(border-*prev_lower<=*lower-border);
    //auto prev=lower;

    /*if (lower==end(numbers)){
        cout<<(prev==end(numbers))<<endl;
        return lower;
    }*/
    return is_left?prev_lower:lower;
};
// set<int>::const_iterator —
// тип итераторов для константного множества целых чисел

int main() {
    set<int> numbers = {1, 4, 6};
    cout <<
         *FindNearestElement(numbers, 0) << " " <<
         *FindNearestElement(numbers, 3) << " " <<
         *FindNearestElement(numbers, 5) << " " <<
         *FindNearestElement(numbers, 6) << " " <<
         *FindNearestElement(numbers, 100) << endl;

    set<int> empty_set;

    cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
    return 0;
}