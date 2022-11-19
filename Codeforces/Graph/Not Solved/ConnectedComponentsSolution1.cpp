#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
int N,M;
vector<unordered_set<int>> adj;
set<int> unVis;
int dfs(int a){
    int counter=1;
    auto it=unVis.begin();
    while(it!=unVis.end()){
        if(adj[a].find(*it)!=adj[a].end()){
            it++;
        }else{
            int cur=*it;
            unVis.erase(it);
            counter+=dfs(cur);
            it=unVis.upper_bound(cur);
        }
    }
    return counter;
}

int main() {
    cin>>N>>M;
    adj.resize(N+1);
    for(int i=1;i<=M;i++){
        int a,b;
        cin>>a>>b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    for(int i=1;i<=N;i++){
        unVis.insert(i);
    }
    int counter=0;
    vector<int> ans;
    for(int i=1;i<=N;i++){
        if(unVis.find(i)!=unVis.end()){
            unVis.erase(i);
            counter++;
            ans.push_back(dfs(i));
        }
    }
    sort(ans.begin(),ans.end());
    cout<<counter<<endl;
    for(int i : ans){
        cout<<i<<" ";
    }


    return 0;
}
