//
// Created by akbar on 15.04.2020.
//
#include <iterator>
#include <algorithm>
#include <string>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
ostream& operator<<(ostream& os, const set<int>& dt)
{
    for(auto x:dt){
        cout<<x<<endl;
    }
    return os;
}
int main()
{
    set<int> s={1,2,3,4,5};
    auto set_begin = begin(s);
    auto set_end = end(s);
    vector<int> vec={1,2,19,7,6,5,18,7,4};
    auto vector_begin = rbegin(vec);
    auto vector_end = rend(vec);
    auto vector_mybegin=begin(vec);
    auto it=is_sorted_until(vector_begin,vector_end);
    vector<int> res(vector_begin,it);
    for(auto x:res){
        cout<<x<<' ';
    }
}