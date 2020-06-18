//
// Created by akbar on 15.04.2020.
//
#include <iterator>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
int main()
{
    cout << "Please, insert two values: ";
    stringstream ss("asdasd asdssd sss");
    istream_iterator<double> eos;
    istream_iterator<double> start(cin);
    vector<double> strings(start, eos);
    //vector<string> more_strings(start, end);

    for(auto x:strings){
        cout<<x<<endl;
    }
    cout<<"lol"<<endl;
    //for(auto x:more_strings){
    //    cout<<x<<endl;
    //}
    return 0;
}