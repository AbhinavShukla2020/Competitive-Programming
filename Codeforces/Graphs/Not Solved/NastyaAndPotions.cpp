#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <cassert>
#include <math.h>
 
using namespace std;
 
#define endl "\n"
#define int int64_t 
#define pb push_back
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR0(i,a) FOR(i,0,a)
#define FOR1(i,a) for (int i = (1); i <= (a); ++i)
#define TRAV(a,x) for (auto& a: x)

using pii = pair<int,int>;
using vi = vector<int>;

int N,K;
vi cost;
vi unlimited;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> dp;

int dfs(int a){
	if(vis[a]){return dp[a];}
	//cout<<"a: "<<a<<endl;
	vis[a]=true;
	int ans=cost[a];
	if(adj[a].size()>0){
		int cur=0;
		TRAV(i,adj[a]){
			cur+=dfs(i);
		}
		// TRAV(i,adj[a]){
		// 	cout<<a<<" "<<i<<" "<<dp[i]<<endl;
		// }
		ans=min(ans,cur);
	}
	dp[a]=ans;
	return ans;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--){
		cost.clear();
		unlimited.clear();
		adj.clear();
		vis.clear();
		cin>>N>>K;
		FOR0(i,N){
			int a; cin>>a; cost.pb(a);
		}
		FOR0(i,K){int a; cin>>a; a--;unlimited.pb(a); cost[a]=0;}
		adj.resize(N);
		FOR0(i,N){
			vis.pb(false);
			dp.pb(0);
			int a;
			cin>>a;
			FOR0(j,a){
				int k; cin>>k; k--;
				adj[i].pb(k);
			}
		}

		FOR0(i,N){
			dfs(i);
		}
		FOR0(i,N){
			cout<<dp[i]<<" ";
		}
		cout<<endl;




	}


	return 0;
}
