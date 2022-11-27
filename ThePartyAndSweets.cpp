#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    long long ans=0;
    long long N,M;
    cin>>N>>M;
    vector<long long> mins(N);
    vector<long long> maxes(M);
    long long greatest=-1;
    for(long long i=0;i<N;i++){
        cin>>mins[i];
        greatest=max(greatest,mins[i]);
    }
    sort(mins.begin(),mins.end(),greater<long long>());
    long long smallest=1000000000;
    for(long long i=0;i<M;i++){
        cin>>maxes[i];
        ans+=maxes[i];
        smallest=min(smallest,maxes[i]);
    }
    if(greatest>smallest) {
        cout << -1 << endl;
        return 0;
    }
    ans+=-(M-1)*mins[0]-mins[1];
    for(long long i : maxes){
        if(mins[0]==i){
            ans+=mins[1]-mins[0];
            break;
        }
    }
    cout<<ans<<endl;
    return 0;

}
