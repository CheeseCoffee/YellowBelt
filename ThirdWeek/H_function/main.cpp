//
// Created by Akbar on 07.03.2020.
//

#include <iostream>
#include "sum_reverse_sort.h"

using namespace std;
int main(){
    cout<<Sum(2,3);
    cout<<Reverse("begin");
    vector<int>a={1,2,4,3};
    Sort(a);
    for(int x:a){
        cout<<x;
    }
    return 0;
}