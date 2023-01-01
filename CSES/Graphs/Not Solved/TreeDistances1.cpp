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
int firstMax[MAXN];
int secondMax[MAXN];
int c[MAXN];

void dfs1(int cur, int prev){
	firstMax[cur]=0;
	secondMax[cur]=0;
	TRAV(u,adj[cur]){
		if(u==prev){continue;}
		dfs1(u,cur);
		if(firstMax[u]+1>firstMax[cur]){
			secondMax[cur]=firstMax[cur];
			firstMax[cur]=firstMax[u]+1;
			c[cur]=u;
		}else if(firstMax[u]+1>secondMax[cur]){
			secondMax[cur]=firstMax[u]+1;
		}
	}
}

void dfs2(int cur,int prev){
	TRAV(i,adj[cur]){
		if(i==prev){continue;}
		if(i==c[cur]){
			if(secondMax[cur]+1>firstMax[i]){
				secondMax[i]=firstMax[i];
				firstMax[i]=secondMax[cur]+1;
				c[i]=-1;
			}else if(secondMax[cur]+1>secondMax[i]){
				secondMax[i]=secondMax[cur]+1;
			}
		}else{
			firstMax[i]=firstMax[cur]+1;
			c[i]=-1;
		}
		dfs2(i,cur);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin>>N;
	FOR0(i,N-1){
		int a,b;
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	dfs1(1,-1);
	dfs2(1,-1);

	FOR1(i,N){
		cout<<firstMax[i]<<" ";
	}




	return 0;
}
