#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    long long N;
    cin>>N;
    vector<pair<long long,long long>> in;
    for(long long i=0;i<N;i++){
        long long a,b;
        cin>>a>>b;
        in.push_back({a,b});
    }
    sort(in.begin(),in.end());
    long long ans=0;
    long long cur=0;
    for(long long i=0;i<N;i++){
        cur+=in[i].first;
        ans+=in[i].second-cur;
    }
    cout<<ans;
    return 0;
}
