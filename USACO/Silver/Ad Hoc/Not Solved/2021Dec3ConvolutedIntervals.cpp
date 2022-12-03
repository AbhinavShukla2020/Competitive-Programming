#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;
int main() {
    long long N,M;
    cin>>N>>M;
    vector<pair<long long,long long>> in(N);
    vector<long long> aFreq(M+1);
    vector<long long> bFreq(M+1);
    for(long long i=0;i<N;i++){
        cin>>in[i].first>>in[i].second;
        aFreq[in[i].first]++;
        bFreq[in[i].second]++;
    }
    vector<long long> pSum(2*M+1);
    for(long long i=0;i<=M;i++){
        for(long long j=0;j<=M;j++){
            pSum[i+j]+=(aFreq[i]*aFreq[j]);
            if(i+j+1<=2*M) {
                pSum[i + j+1] -= (bFreq[i] * bFreq[j]);
            }
        }
    }
    cout<<pSum[0]<<endl;
    for(long long i=1;i<=2*M;i++){
        pSum[i]+=pSum[i-1];
        cout<<pSum[i]<<endl;
    }
    return 0;
}
