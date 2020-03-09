#include <iostream>
#include <vector>
#include <cstdint>
#include <sstream>
using namespace std;
int main(){
    int N,R,W,H,D;
    uint64_t S=0;
    uint64_t P=1;
    cin>>N>>R;
    for(int i=0;i<N;i++){
        cin>>W>>H>>D;
        S+= static_cast<uint64_t>(R)*W*H*D;
    }
    cout<<S;
    return 0;
}