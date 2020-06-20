//
// Created by akbar on 19.06.2020.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;
bool myfuncupper(string a,  string  b) {
    for(auto it=a.begin();it!=a.end();it++){
        if(*it<=*(b.begin()+(it-a.begin()))){
            return true;
        }
    }
    return false;
};
bool myfunclower(string a, string b) {
    for(auto it=b.begin();it!=b.end();it++){
        if(*it<*(a.begin()+(it-b.begin()))){
            return true;
        }
    }
    return false;
};
template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, const string& prefix){
    auto upper=upper_bound(range_begin,range_end,prefix,myfuncupper);
    if(upper==range_end){
        return {range_end,range_end};
    }
    auto lower=lower_bound(range_begin,range_end,prefix,myfunclower);
    return {upper,lower};
}

int main() {
    const vector<string> sorted_strings = {"moscow", "motovilikha", "murmansk"};

    const auto mo_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
    for (auto it = mo_result.first; it != mo_result.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    const auto mt_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
    cout << (mt_result.first - begin(sorted_strings)) << " " <<
         (mt_result.second - begin(sorted_strings)) << endl;

    const auto na_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
    cout << (na_result.first - begin(sorted_strings)) << " " <<
         (na_result.second - begin(sorted_strings)) << endl;

    return 0;
}
