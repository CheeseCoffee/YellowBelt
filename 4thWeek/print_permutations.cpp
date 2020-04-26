//
// Created by Akbar on 26.04.2020.
//
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin>>N;
    vector<int>v;
    for(int i=N;i>0;i--){
        v.push_back(i);
    }
    do {
        for(auto x:v){
            cout<<x<<' ';
        }
        cout<<endl;
    } while(prev_permutation(v.begin(),v.end()));
    return 0;
}
