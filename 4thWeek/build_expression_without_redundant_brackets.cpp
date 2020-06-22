//
// Created by Akbar on 22.06.2020.
//

#include <iostream>
#include <string>
#include <sstream>
#include <deque>
#include <iterator>
using namespace std;
int main(){
    //stringstream ss("8\n5\n* 3\n- 6\n/ 1\n- 6\n/ 1");
    deque<string>deq;
    string buff;
    //---------
    cin>>buff;
    string old;
    string neww1,neww2;
    int N;
    //---------
    cin>>N;
    for(int i=0;i<N;i++){

        old=neww1;
        //---------
        cin>>neww1;
        //cout<<old<<neww1<<endl;
        //---------
        cin>>neww2;
        if((neww1=="*" or neww1=="/") and (old=="+" or old=="-")){
            deq.push_back(buff.append(") ").append(neww1).append(" ").append(neww2));
            deq.push_front("(");
            buff.erase();
        }else{
            //buff=buff+" "+neww1+" "+neww2;
            buff=buff.append(" ").append(neww1).append(" ").append(neww2);
        }
    }
    if(!buff.empty()){
        deq.push_back(buff);
    }
    if (!deq.empty()) { // если дек не пуст
        // вывод на экран элементов дека
        copy( deq.begin(), deq.end(), ostream_iterator<string>(cout,"") ); // вывод на экран элементов дека
    }
    return 0;
}