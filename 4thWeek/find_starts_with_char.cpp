//
// Created by akbar on 19.06.2020.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;
bool myfuncupper(char a,  string  b) {
    return(a <= b[0]);
};
bool myfunclower(string a, char b) {
    return(a[0] <= b);
};
template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, char prefix){
    auto upper=upper_bound(range_begin,range_end,prefix,myfuncupper);
    if(upper==range_end){
        return {range_end,range_end};
    }
    auto lower=lower_bound(range_begin,range_end,prefix,myfunclower);
    return {upper,lower};
}

int main() {
    const vector<string> sorted_strings = {"moscow", "murmansk", "vologda"};

    const auto m_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
    for (auto it = m_result.first; it != m_result.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    const auto p_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
    cout << (p_result.first - begin(sorted_strings)) << " " <<
         (p_result.second - begin(sorted_strings)) << endl;

    const auto z_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
    cout << (z_result.first - begin(sorted_strings)) << " " <<
         (z_result.second - begin(sorted_strings)) << endl;

    return 0;
}