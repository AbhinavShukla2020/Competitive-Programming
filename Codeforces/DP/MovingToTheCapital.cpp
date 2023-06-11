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
int dp[10000000];
void dfs(int cur, vector<bool>& vis,vector<int> adj[],vi& dist){
	//cout<<cur<<" : "<<endl<<endl;
	dp[cur]=dist[cur];
	vis[cur]=true;
	//int ans=100000000000;
	TRAV(i,adj[cur]){

		if(!vis[i] && dist[i]>dist[cur]){
			//cout<<i<<endl;
			dfs(i,vis,adj,dist);
			
		}
		if(dist[i]>dist[cur]){
			dp[cur]=min(dp[i],dp[cur]);
		}
		if(dist[i]<=dist[cur]){
			dp[cur]=min(dist[i],dp[cur]);
		}
	}
	//return ans;
}
int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--){
		int N,M;
		cin>>N>>M;
		vector<int> adj[N+1];
		FOR0(i,M){
			int a,b;
			cin>>a>>b;
			adj[a].pb(b);
		}
		vi dist(N+1,10000000000);
		dist[1]=0;
		queue<int> cur;
		cur.push(1);

		vector<bool> vis(N+1,false);
		vis[1]=true;
		while(!cur.empty()){

			int top=cur.front();
			//cout<<"top: "<<top<<endl;
			cur.pop();
			TRAV(i,adj[top]){
				//cout<<" "<<i<<endl;
				if(vis[i]){
					continue;
				}
				//cout<<"  "<<i<<endl;
				vis[i]=true;
				dist[i]=min(dist[top]+1,dist[i]);
				cur.push(i);
			}
			// cout<<endl<<endl;
			// FOR1(i,N){
			// 	cout<<dist[i]<<" ";
			// }
			// cout<<endl<<endl;
		}
		
		FOR1(i,N){
			dp[i]=1000000000000;
			vis[i]=false;
			//cout<<dist[i]<<" ";
		}
		//cout<<endl;
		//cout<<endl<<endl<<endl<<endl;
		FOR1(i,N){
			if(!vis[i]){
				dfs(i,vis,adj,dist);
				//cout<<" done "<<endl;
			}
		}
		FOR1(i,N){
			cout<<dp[i]<<" ";
		}
		cout<<endl;



	}


	return 0;
}
