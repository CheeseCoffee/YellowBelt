//
// Created by Akbar on 25.02.2020.
//
#include <iostream>
#include <vector>
#include <map>
#include <utility>
using namespace std;

template <typename T>
T Sqr(const T& x);

template <typename T>
vector<T> Sqr(const vector<T>& vi);

template <typename First,typename Second>
pair<First,Second> Sqr(const pair<First,Second>& p);

template <typename Key, typename Value>
map<Key,Value> Sqr(const map<Key,Value>& m);

template <typename T>
vector<T> Sqr(const vector<T>& vi){
    vector<T>vi1;
    for(const T&i:vi){
        vi1.push_back(Sqr(i));
    }
    return vi1;
};

template <typename Key, typename Value>
map<Key,Value> Sqr(const map<Key,Value>& m){
    map<Key,Value>m1;
    for(const auto& i:m){
        m1[i.first]=Sqr(i.second);
    }
    return m1;
};

template <typename First,typename Second>
pair<First,Second> Sqr(const pair<First,Second>& p){
    return make_pair(Sqr(p.first),Sqr(p.second));
}

template<typename T>
T Sqr(const T &x) {
    return x*x;
};


int main(){
    // Пример вызова функции
    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v)) {
        cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
            {4, {2, 2}},
            {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }
    return 0;
}