#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>
 
using namespace std;
 
using pii = pair<int,int>;
using vi = vector<int>;
 
#define pb push_back
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR0(i,a) FOR(i,0,a)
#define FOR1(i,a) for (int i = (1); i <= (a); ++i)
#define TRAV(a,x) for (auto& a: x)
#define int int64_t

const int MAXN=1e5+1;
int N,M;
vector<vi> adj(MAXN);
bool vis1[MAXN];
bool vis2[MAXN];
set<int> cur;
set<pii> ans; //
bool needOddDegree[MAXN];
set<pii> spanningEdges; //
 
void dfs(int a,int prev){
	//cout<<a<<endl;
	vis1[a]=true;
	cur.insert(a);
	TRAV(u,adj[a]){
		if(vis1[u] && u!=prev && u>a){
			//cout<<"SPANNING EDGE: "<<a<<" "<<u<<endl;
			ans.insert({a,u});
			if(needOddDegree[u]){
				needOddDegree[u]=false;
			}else{
				needOddDegree[u]=true;
			}
			spanningEdges.insert({a,u});
		}else if(!vis1[u]){
			dfs(u,a);
		}
	}
}
 
bool dfs2(int a){
	vis2[a]=true;
	int curCount=0;
	TRAV(u,adj[a]){
		if(!vis2[u] && spanningEdges.find({a,u})==spanningEdges.end()){
			if(dfs2(u)){
				ans.insert({a,u});
			}else{
				ans.insert({u,a});
				curCount++;
			}
		}
	}
	if(needOddDegree[a]){
		if(curCount%2==1){
			return false;
		}else{
			return true;
		}
	}else{
		if(curCount%2==0){
			return false;
		}else{
			return true;
		}
	}
}
 
int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>M;
	FOR1(i,N){
		vis1[i]=false;
		vis2[i]=false;
		needOddDegree[i]=false;
	}
 
	vector<pii> edges;
 
	FOR0(i,M){
		int a,b; cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
		edges.pb({a,b});
 
		
	}
 	FOR1(i,N){
 		if(!vis1[i]){
 			dfs(i,-1);
 			dfs2(i);
 			// ans.clear();
 			// spanningEdges.clear();
 		}
 	}
	// dfs(1,-1);
	// //cout<<endl<<endl;
	// dfs2(1);
 	vector<vi> adj2(N+1);
 	FOR1(i,N){
 		adj2[i].resize(0);
 	}
 	TRAV(i,ans){
 		adj2[i.second].pb(i.first);
 	}
 	FOR1(i,N){
 		if(adj2[i].size()%2!=0){
 			cout<<"IMPOSSIBLE";
 			return 0;
 		}

 	}
	TRAV(i,edges){
		if(ans.find(i)==ans.end()){
			cout<<i.first<<" "<<i.second<<endl;
		}else{
			cout<<i.second<<" "<<i.first<<endl;
		}
	}
 
 
 
	return 0;
}
