#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
long long max2(long long a, long long b){
    if(a>b){
        return a;
    }
    return b;
}
int main() {
    freopen("berries.in","r",stdin);
    freopen("berries.out","w",stdout);
    long long N,K;
    cin>>N>>K;
    vector<long long> trees(N);
    for(long long i=0;i<N;i++){
        cin>>trees[i];
    }
    sort(trees.begin(),trees.end());
    long long finalAns=-1;
    for(long long i=1;i<=trees[N-1];i++){
        long long used=0;
        for(long long k : trees){
            used+=k/i;
        }
        if(used<K/2){
            break;
        }

        vector<long long> remainders;
        for(long long k : trees){
            remainders.push_back((k%i));
        }
        sort(remainders.begin(),remainders.end(),greater<long long>());
        long long ans=0;
        for(long long j=0;used+j<K;j++){
            ans+=remainders[j];
        }
        ans+=i*max2(0,min(K/2,(used-K/2)));
        finalAns=max(ans,finalAns);
    }
    cout<<finalAns;
    return 0;
}
