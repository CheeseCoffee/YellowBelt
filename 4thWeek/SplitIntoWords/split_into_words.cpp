//
// Created by Акбар on 10.03.2020.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

/*vector<string> SplitIntoWords(const string& s){
    vector<string> string;
    stringstream ss;
    for(auto it=begin(s);it!=end(s);++it){
        if(*it==' '){
            string.push_back(ss.str());
            ss.str("");
        }else{
            ss<<*it;
        }
    }
    string.push_back(ss.str());
    return string;
};*/

vector<string> SplitIntoWords(const string& s){
    vector<string> result;
    auto str_begin=begin(s);
    const auto str_end=end(s);
    while(true){
        auto it=find(str_begin,str_end,' ');
        result.push_back(string(str_begin,it));
        if(it==str_end){
            break;
        }else{
            str_begin=it+1;
        }
    }
    return result;
}

int main() {
    string s = "C Cpp Java Python";
    vector<string> words = SplitIntoWords(s);
    cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
        if (it != begin(words)) {
            cout << "/";
        }
        cout << *it;
    }
    cout << endl;
    return 0;
}