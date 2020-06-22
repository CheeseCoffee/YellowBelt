//
// Created by akbar on 19.06.2020.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;
bool myfuncupper(string a/*value - mos*/,  string  b/*element - mur*/) {
    for(auto it=a.begin();it!=a.end();it++){
        if(*it<*(b.begin()+(it-a.begin()))){
            return true;
        }
        if(*it>*(b.begin()+(it-a.begin()))){
            return false;
        }
    }
    //if(a.length()<b.length()){ return true;}
    return false;
};
bool myfunclower(string a/*element - mo*/, string b/*value - mos*/) {
    //cout<<a<<b<<endl;
    for(auto it=b.begin();it!=b.end();it++){//m->o->s
        //cout<<a<<" "<<b<<"/"<<*(a.begin()+(it-b.begin()))<<"<"<<*it<<endl;
        if(*it>*(a.begin()+(it-b.begin()))){//m>m o>o s>-
            //cout<<"heretrue";
            return true;
        }
        if(*it<*(a.begin()+(it-b.begin()))){//m>m o>o s>-
            //cout<<"herefalse";
            return false;
        }
    }
    return false;
};
template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, const string& prefix){
    auto lower=lower_bound(range_begin,range_end,prefix,myfunclower);
    if(lower==range_end){
        return {range_end,range_end};
    }
    auto upper=upper_bound(range_begin,range_end,prefix,myfuncupper);
    return {lower,upper};
}

int main() {
    const vector<string> sorted_strings = {"moscow", "motovio", "murmansl"};

    const auto mo_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
    for (auto it = mo_result.first; it != mo_result.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    const auto mt_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
    cout << (mt_result.first - begin(sorted_strings)) << " " <<
         (mt_result.second - begin(sorted_strings)) << endl;

    const auto na_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
    cout << (na_result.first - begin(sorted_strings)) << " " <<
         (na_result.second - begin(sorted_strings)) << endl;

    /*string prefix="mo";
    string upper_bound=prefix;
    ++upper_bound[upper_bound.size()-1];
    cout<<upper_bound;
    cout<< (lower_bound(sorted_strings.begin(),sorted_strings.end(),upper_bound)-sorted_strings.begin());*/
    return 0;
}
