//
// Created by Akbar on 19.02.2020.
//
#include<iostream>
#include<vector>
#include<map>
#include <tuple>
#include <string>
#include <algorithm>
using namespace std;
enum class Lang {
    DE, FR, IT
};

struct Region {
    string std_name;
    string parent_std_name;
    map<Lang, string> names;
    int64_t population;
};
/*
bool EqualRegion(const Region& lhs,const Region& rhs){
    if(tie(lhs.std_name,lhs.parent_std_name,lhs.population)!=tie(rhs.std_name,rhs.parent_std_name,rhs.population)){return false;}
    if(lhs.names.size()!=rhs.names.size()){return false;}
    for(const auto& x:lhs.names){
        if(rhs.names.at(x.first)!=x.second){return false;}
    }
    return true;
}

int FindMaxRepetitionCount1(const vector<Region>& regions){
    int sum=0;
    int compare=0;
    for(int i=0;i<regions.size();i++){
        for(int j=0;j<regions.size();j++){
            if(EqualRegion(regions[i],regions[j])&&(i!=j)){
                sum++;
            }
        }
        if(sum>compare){compare=sum;}
        sum=0;
    }
    return compare+1;
};

int FindMaxRepetitionCount(const vector<Region>& regions){
    if(regions.size()==0){return 0;}
    map<Region,int>mymap;
    int max=0;
    for(const Region& region:regions){
        if(mymap.count(region)==0){
            mymap[region]=1;
        }else{
            mymap[region]++;
        }
        if(mymap[region]>max){max=mymap[region];}
    }
    return max;
};

bool operator<(const Region& lhs,const Region& rhs){

    if(tie(lhs.std_name,lhs.parent_std_name,lhs.population)!=tie(rhs.std_name,rhs.parent_std_name,rhs.population)){return tie(lhs.std_name,lhs.parent_std_name,lhs.population)<tie(rhs.std_name,rhs.parent_std_name,rhs.population);}
    if(lhs.names.count(Lang::DE)!=0){
        if(rhs.names.count(Lang::DE)==0){return true;}
        if(lhs.names.at(Lang::DE)<rhs.names.at(Lang::DE)){ return true;}
    }
    if(lhs.names.count(Lang::FR)!=0){
        if(rhs.names.count(Lang::FR)==0){return true;}
        if(lhs.names.at(Lang::FR)<rhs.names.at(Lang::FR)){ return true;}
    }
    if(lhs.names.count(Lang::IT)!=0){
        if(rhs.names.count(Lang::IT)==0){return true;}
        if(lhs.names.at(Lang::IT)<rhs.names.at(Lang::IT)){ return true;}
    }
    return false;
}*/

bool operator<(const Region& lhs, const Region& rhs) {
    return tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) <
           tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

int FindMaxRepetitionCount(const vector<Region>& regions) {
    int result = 0;
    map<Region, int> repetition_count;
    for (const Region& region : regions) {
        result = max(result, ++repetition_count[region]);
    }
    return result;
}

int main() {
    cout << FindMaxRepetitionCount({
                                           {
                                                   "Moscow",
                                                   "Russia",
                                                   {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                                                   89
                                           }, {
                                                   "Russia",
                                                   "Eurasia",
                                                   {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
                                                   89
                                           }, {
                                                   "Moscow",
                                                   "Russia",
                                                   {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                                                   89
                                           }, {
                                                   "Moscow",
                                                   "Russia",
                                                   {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                                                   89
                                           }, {
                                                   "Russia",
                                                   "Eurasia",
                                                   {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
                                                   89
                                           },
                                   }) << endl;

    cout << FindMaxRepetitionCount({
                                           {
                                                   "Moscow",
                                                   "Russia",
                                                   {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                                                   89
                                           }, {
                                                   "Russia",
                                                   "Eurasia",
                                                   {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
                                                   89
                                           }, {
                                                   "Moscow",
                                                   "Russia",
                                                   {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
                                                   89
                                           }, {
                                                   "Moscow",
                                                   "Toulouse",
                                                   {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                                                   89
                                           }, {
                                                   "Moscow",
                                                   "Russia",
                                                   {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
                                                   31
                                           },
                                   }) << endl;

    return 0;
}
