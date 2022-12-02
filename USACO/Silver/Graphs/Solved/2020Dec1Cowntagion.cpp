#include <iostream>
#include <vector>
using namespace std;
long long LOG2(long long a){
    long long counter=1;
    long long ans=0;
    while(counter<(a)){
        ans++;
        counter*=2;
    }
    return ans;
}
int main() {
    long long N;
    cin>>N;
    long long ans=N-1;
    vector<vector<long long>> adj(N+1);
    for(long long i=0;i<N-1;i++){
        long long a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    adj[1].push_back(-1);
    for(long long i=1;i<=N;i++){
        ans+=LOG2(adj[i].size());
    }
    cout<<ans;
    return 0;
}
