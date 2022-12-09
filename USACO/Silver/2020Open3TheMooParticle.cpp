#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
long long N;
vector<vector<long long>> getComponents(vector<vector<long long>> adj){
    //ASSUMING ONE-INDEXED
    //CHANGE TO N=adj.size() IF NOT
    //long long N=adj.size()-1;
    bool vis[N];
    vector<vector<long long>> components;
    //ASSUMING ONE-INDEXED. CHANGE IF NEEDED
    for(long long i=0;i<=N-1;i++){
        vis[i]=false;
    }

    //ASSUMING ONE-INDEXED. CHANGE IF NEEDED
    for(long long a=0;a<=N-1;a++){
        if(vis[a]==false){
            vector<long long> cur;
            stack<long long> dfs;
            dfs.push(a);
            vis[a]=true;
            while(!dfs.empty()){
                long long k=dfs.top();
                cur.push_back(k);
                dfs.pop();
                for(long long i : adj[k]){
                    if(vis[i]==false){
                        dfs.push(i);
                        vis[i]=true;
                    }
                }

            }
            components.push_back(cur);
        }

    }
    return components;
}
void fileIO(string filename) {
    freopen((filename + ".in").c_str(), "r", stdin);
    freopen((filename + ".out").c_str(), "w", stdout);
}
int main() {
    fileIO("moop");
    cin>>N;
    vector<pair<long long,long long>> x;
    vector<long long> y;
    for(long long i=0;i<N;i++){
        long long a,b;
        cin>>a>>b;
        x.push_back({a,b});
    }

    sort(x.begin(),x.end());
    vector<long long> backYMax;
    backYMax.push_back(-10000000000000000);
    for(long long i=N-1;i>=0;i--){
        y.push_back(x[i].second);
        if(backYMax.size()!=0){
            backYMax.push_back(max(backYMax[backYMax.size()-1],x[i].second));
        }else{
            backYMax.push_back(x[i].second);
        }
    }

    set<long long> curY;
    curY.insert(100000000000000);
    long long ans=0;
    for(long long i=0;i<N;i++){
        long long cy=x[i].second;
        if(*curY.begin()>cy && *curY.begin()>backYMax[N-i-1]){
            ans++;
        }
        curY.insert(cy);
    }
    cout<<ans;

    return 0;
}
