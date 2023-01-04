#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <unordered_set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>
 
using namespace std;
 
using pii = pair<int,int>;
using vi = vector<int>;

#define int int64_t 
#define pb push_back
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR0(i,a) FOR(i,0,a)
#define FOR1(i,a) for (int i = (1); i <= (a); ++i)
#define TRAV(a,x) for (auto& a: x)

const int MAXN=2e5+1;
int N,d;
vector<vi> adj(MAXN);
int deepestRoute[MAXN];
bool inPath[MAXN];
set<int> bre[MAXN];
int ans=0;

int dfs2(int cur, int prev){
	int curAns=0;
	TRAV(u,adj[cur]){
		if(u==prev) continue;
		if(inPath[u]==true && curAns<1){
			curAns=1;
		}
		int k=dfs2(u,cur);
		if(k==0){
			continue;
		}
		curAns=max(k+1,curAns);
	}
	deepestRoute[cur]=curAns;
	return curAns;
}

void dfs3(int cur,int prev){
	TRAV(u,adj[cur]){
		if(u==prev){continue;}
		if(bre[u].size()==2){
			ans+=4;
			dfs3(u,cur);
			continue;
		}
		if(deepestRoute[u]==0 && inPath[u]==false){
			continue;
		}
		if((deepestRoute[u]+1)>d){
			ans+=4;
		}else{
			ans+=2;
		}
		dfs3(u,cur);
	}
}

void dfs4(int cur, int prev){
	TRAV(u,adj[cur]){
		if(u==prev){continue;}
		dfs4(u,cur);
		TRAV(i,bre[u]){
			bre[cur].insert(i);
		}
	}
}
int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>d;
	FOR0(i,N-1){
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	int a;
	cin>>a;
	FOR0(i,a){
		int b;
		cin>>b;
		b--;
		bre[b].insert(1);
		inPath[b]=true;
	}
	int b;
	cin>>b;
	FOR0(i,b){
		int c;
		cin>>c;
		c--;
		bre[c].insert(2);
		inPath[c]=true;
	}
	dfs2(0,-1);
	dfs4(0,-1);
	dfs3(0,-1);
	cout<<ans<<endl;


	return 0;
}
