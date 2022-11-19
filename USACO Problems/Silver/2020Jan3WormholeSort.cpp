#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;
struct portal{
    int start;
    int end;
    int width;
};
int N,M;
vector<int> widths;
vector<int> nums;
vector<int> needChanging;
vector<int> numsInverted;
vector<portal> portals;
//vector<vector<int>> componentsSwap;
vector<vector<int>> getComponents(vector<vector<int>> adj){
    //ASSUMING ONE-INDEXED
    //CHANGE TO N=adj.size() IF NOT
    //int N=adj.size()-1;
    bool vis[N];
    vector<vector<int>> components;
    //ASSUMING ONE-INDEXED. CHANGE IF NEEDED
    for(int i=1;i<=N;i++){
        vis[i]=false;
    }

    //ASSUMING ONE-INDEXED. CHANGE IF NEEDED
    for(int a=1;a<=N;a++){
        if(vis[a]==false){
            vector<int> cur;
            stack<int> dfs;
            dfs.push(a);
            vis[a]=true;
            while(!dfs.empty()){
                int k=dfs.top();
                cur.push_back(k);
                dfs.pop();
                for(int i : adj[k]){
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


map<int,int> componentsColoring(vector<vector<int>> adj){
    //ASSUMING ONE-INDEXED
    //CHANGE TO N=adj.size() IF NOT
    //int N=adj.size()-1;
    bool vis[N+1];
    map<int,int> coloring;
    //ASSUMING ONE-INDEXED. CHANGE IF NEEDED
    for(int i=1;i<=N;i++){
        vis[i]=false;
    }
    int curColor=1;
    //ASSUMING ONE-INDEXED. CHANGE IF NEEDED
    for(int a=1;a<=N;a++){
        if(vis[a]==false){
            stack<int> dfs;
            dfs.push(a);
            vis[a]=true;
            while(!dfs.empty()){
                int k=dfs.top();
                coloring[k]=curColor;
                dfs.pop();
                for(int i : adj[k]){
                    if(vis[i]==false){
                        dfs.push(i);
                        vis[i]=true;
                    }
                }
            }
            curColor++;
        }

    }
    return coloring;
}


bool f(int max){
    vector<vector<int>> adj(N+1);
    for(portal i : portals){
        if(i.width>=max){
            adj[i.start].push_back(i.end);
            adj[i.end].push_back(i.start);
        }
    }
    map<int,int> newComponents = componentsColoring(adj);
    bool works=true;
    for(int i : needChanging){
        if(newComponents[nums[i]]!=newComponents[numsInverted[i]]){return false;}
    }
    return works;
}

int last_true(int lo, int hi) {
    // if none of the values in the range work, return lo - 1
    lo--;
    while (lo < hi) {
        // find the middle of the current range (rounding up)
        int mid = lo + (hi - lo + 1) / 2;
        if (f(mid)) {
            // if mid works, then all numbers smaller than mid also work
            lo = mid;
        } else {
            // if mid does not work, greater values would not work either
            hi = mid - 1;
        }
    }
    return lo;
}


int main() {
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    cin>>N>>M;
    nums.resize(N+1);
    numsInverted.resize(N+1);

    nums[0]=0;
    map<int,int> numToPlace;
    for(int i=1;i<=N;i++){
        cin>>nums[i];
        numToPlace[nums[i]]=i;
        if(i!=nums[i]){
            needChanging.push_back(i);
        }
    }
    vector<int> copy=nums;
    sort(copy.begin(),copy.end());
    if(copy==nums){
        cout<<-1<<endl;
        return 1;
    }



    for(int i=0;i<M;i++){
        int a,b,c;
        cin>>a>>b>>c;
        portals.push_back({a,b,c});
        widths.push_back(c);
    }
    sort(widths.begin(),widths.end());

    vector<vector<int>> adj(N+1);

    for(int i=1;i<=N;i++){
        numsInverted[i]=nums[nums[i]];
    }

    for(int i=1;i<=N;i++){
        if(nums[i]!=numsInverted[i]){
            adj[nums[i]].push_back(numsInverted[i]);
        }
    }

    int ans=last_true(widths[0],widths[M-1]);
    cout<<ans<<endl;





    return 0;
}
