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

using ll = long long;
using pii = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;

#define pb push_back
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR0(i,a) FOR(i,0,a)
#define FOR1(i,a) for (int i = (1); i <= (a); ++i)
#define TRAV(a,x) for (auto& a: x)

const int MAXN=2e5+1;
vector<vi> adj(MAXN);
vi subTreeSize(MAXN);
vl subTreeDistSum(MAXN);
vl ans(MAXN);
int N;

void dfs1(int a, int prev){
	subTreeSize[a]=1;
	TRAV(u,adj[a]){
		if(u==prev){continue;}
		dfs1(u,a);
		subTreeSize[a]+=subTreeSize[u];
		subTreeDistSum[a]+=subTreeDistSum[u]+subTreeSize[u];
	}
}

void dfs(int a,int prev){
	if(prev!=-1){
		ans[a]=ans[prev]-subTreeSize[a]+(N-subTreeSize[a]);
	}else{
		ans[a]=subTreeDistSum[a];
	}
	TRAV(u,adj[a]){
		if(u==prev){continue;}
		dfs(u,a);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//int N;
	cin>>N;
	FOR0(i,N-1){
		int a,b;
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs1(1,-1);
	dfs(1,-1);
	FOR1(i,N){
		cout<<ans[i]<<" ";
	}


	return 0;
}
