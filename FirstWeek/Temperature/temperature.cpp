#include <iostream>
#include <cstdint>
#include <vector>
using namespace std;
int main(){
    int N;
    cin>>N;
    vector<int>t;
    int K;
    int L=0;
    int64_t sum=0;
    for(int i=0;i<N;i++){
        cin>>K;
        t.push_back(K);
        sum+=K;
    }
    int avg=sum/N;
    for(int i=0;i<N;i++){
        if(t[i]>avg){
            L++;
        }
    }
    cout<<L<<endl;
    int j=0;
    for(int i=0;i<N;i++){
        if(t[i]>avg){
            if(!j){
                cout<<i;
                j=1;
            }else{
                cout<<" "<<i;
            }
        }
    }
    return 0;
}
