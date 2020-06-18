//
// Created by Akbar on 08.06.2020.
//

#include <iterator>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
int main(){
    stringstream ss("huihihihi hihihih hhh");
    cout<<"enter"<<endl;
    istream_iterator<string>start(cin);
    istream_iterator<string>end;
    vector<string>vec(start,end);
    vector<string>morevec(start,end);
    for(auto x:vec){
        cout<<x<<endl;
    }
    for(auto x:morevec){
        cout<<x<<endl;
    }
    cout<<*start++<<endl;
    return 0;
}