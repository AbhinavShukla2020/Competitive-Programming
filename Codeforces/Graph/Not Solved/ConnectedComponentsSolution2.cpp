#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_set>
#include <map>
using namespace std;
int N,M;
const int MAX_N=200000;
int curColor=1;
vector<unordered_set<int>> adj;
vector<bool> vis;
int sz[MAX_N];
int group[MAX_N];
vector<int> curGroup;

void dfs(int a){
    vis[a]=true;
    for(int i=1;i<=N;i++){
        if(a!=i && adj[a].find(i)==adj[a].end()){
            if(group[i]==1){
                curColor=1;
            }else if(group[i]!=1 && vis[i]==false){
                curGroup.push_back(i);
                dfs(i);
            }
        }
    }
}

int main() {
    cin>>N>>M;
    vis.resize(N+1);
    for(int i=0;i<=N;i++){
        vis[i]=false;
    }
    adj.resize(N+1);
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    int amoOfGroups=1;
    for(int i=1;i<=N;i++){
        if(N-adj[i].size()>N/2){
            sz[1]++;
            vis[i]=true;
            amoOfGroups=2;
            curColor=2;
            group[i]=1;
        }
    }

    for(int i=1;i<=N;i++){

        if(!group[i]){
            curColor=amoOfGroups;
            curGroup.push_back(i);
            dfs(i);
            for(int k : curGroup){
                group[k]=curColor;
                sz[curColor]++;
            }
            
            curGroup.clear();
            if(curColor==amoOfGroups) {
                amoOfGroups++;
            }
        }
    }

    
    int cur=amoOfGroups;
    cout << cur - 1 << endl;
    sort(sz, sz + cur);
    for (int i = 1; i < cur; i++) {
        cout << sz[i] << ' ';
    }

    return 0;
}
