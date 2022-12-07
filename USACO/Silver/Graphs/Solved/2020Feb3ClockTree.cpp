#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;
int main() {
    freopen("clocktree.in", "r", stdin);
    freopen("clocktree.out", "w", stdout);
    int N;
    cin>>N;
    int clocks[N+1];
    for(int i=1;i<=N;i++){
        cin>>clocks[i];
    }
    vector<int> adj[N+1];
    for(int i=0;i<N-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ans=0;
    for(int i=1;i<=N;i++){
        int curClocks[N+1];
        int counter=1;
        int counter2=0;
        for(int j : clocks){
            if(counter2!=0){
                curClocks[counter]=j;
                counter++;
            }
            counter2++;
        }

        map<int,int> parent;
        vector<int> order;
        queue<int> q;
        q.push(i);
        vector<int> vis(N+1,false);
        while (!q.empty()) {
            int x = q.front(); q.pop();
            vis[x]=true;
            if(x!=i){
                order.push_back(x);
            }
            for (int t: adj[x]){
                if(!vis[t]) {
                    parent[t] = x;
                    q.push(t);
                }
            }
        }

        queue<int> curNodes;
        for(int j=order.size()-1;j>=0;j--){
            curNodes.push(order[j]);
        }

        while(!curNodes.empty()){
            int cur=curNodes.front();
            curClocks[parent[cur]]+=(12-curClocks[cur]);
            curClocks[parent[cur]]=(curClocks[parent[cur]] % 12);
            curClocks[cur]=0;
            curNodes.pop();
        }

        if(curClocks[i]==1 || curClocks[i]==0){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
