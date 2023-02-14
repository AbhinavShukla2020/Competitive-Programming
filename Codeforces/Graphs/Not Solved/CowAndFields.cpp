#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>
 
using namespace std;
 
using pii = pair<int,int>;
using vi = vector<int>;

#define endl "\n"
#define int int64_t 
#define pb push_back
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR0(i,a) FOR(i,0,a)
#define FOR1(i,a) for (int i = (1); i <= (a); ++i)
#define TRAV(a,x) for (auto& a: x)

int N,M,K;
set<int> special;
vi special2;
int x[200100];
int y[200100];
vector<vector<int>> adj;
bool cmp(int a, int b){
	return (x[a]-y[a])<(x[b]-y[b]);
}
int32_t main(){


	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>M>>K;
	// if(N==10 && M==15 && K==8){
	// 	cout<<3<<endl;
	// 	return 0;
	// }
	adj.resize(N+3);
	FOR0(i,K){
		int a;
		cin>>a;
		special.insert(a);
		special2.pb(a);
	}
	FOR0(i,M){
		int a,b;
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	int ans;
	
	//bfs1
	queue<pii> cur;
	cur.push({1,0});
	vector<bool> vis(N+5,false);
	vis[1]=true;
	while(!cur.empty()){
		pii curNode=cur.front();
		if(curNode.first==N){
			ans=curNode.second;
		}
		cur.pop();
		
			x[curNode.first]=curNode.second;
		
		TRAV(i,adj[curNode.first]){
			if(!vis[i]){
				cur.push({i,curNode.second+1});
				vis[i]=true;
			}
		}
	}

	//bfsN
	while(!cur.empty()){
		cur.pop();
	}
	cur.push({N,0});
	vector<bool> vis2(N+5,false);
	vis2[N]=true;
	while(!cur.empty()){
		pii curNode=cur.front();
		cur.pop();
		
			y[curNode.first]=curNode.second;
		
		TRAV(i,adj[curNode.first]){
			if(!vis2[i]){
				cur.push({i,curNode.second+1});
				vis2[i]=true;
			}
		}
	}

	int ans2=-1;
	sort(special2.begin(),special2.end(),cmp);
	int suffix[K];
	int cnt=0;
	for(int i=(K-1);i>=0;i--){
		if(i==(K-1)){
			suffix[K-1-i]=y[special2[i]];
			continue;
		}
		suffix[K-1-i]=max(y[special2[i]],suffix[K-1-i-1]);
	}
	FOR0(i,K-1){
		ans2=max(ans2,x[special2[i]]+suffix[K-i-2]+1);
	}
	cout<<min(ans,ans2)<<endl;
	return 0;
}
