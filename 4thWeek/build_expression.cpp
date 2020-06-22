//
// Created by Akbar on 22.06.2020.
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main(){
    //stringstream ss("8\n3\n* 3\n- 6\n/ 1");
    string s;
    cin>>s;
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        cout<<"(";
    }
    cout<<s;
    for(int i=0;i<N;i++){
        string neww1,neww2;
        cin>>neww1;
        cin>>neww2;
        cout<<") "<<neww1<<" "<<neww2;
    }
    return 0;
}