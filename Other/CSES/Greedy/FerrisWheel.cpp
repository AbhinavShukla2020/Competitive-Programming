#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    long long N,X;
    cin>>N>>X;
    vector<long long> weights(N);
    for(long long i=0;i<N;i++){
        cin>>weights[i];
    }
    sort(weights.begin(),weights.end());
    long long ans=N;
    long long pointer2=N-1;
    long long pointer1=0;
    while(pointer2>pointer1){
        if(weights[pointer2]+weights[pointer1]<=X){
            ans--;
            pointer2--;
            pointer1++;
        }else{
            pointer2--;
        }
    }
    cout<<ans<<endl;
    return 0;
}
