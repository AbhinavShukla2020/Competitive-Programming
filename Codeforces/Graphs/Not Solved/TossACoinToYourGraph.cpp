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

#define endl "\n"
#define int int64_t 
#define pb push_back
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR0(i,a) FOR(i,0,a)
#define FOR1(i,a) for (int i = (1); i <= (a); ++i)
#define TRAV(a,x) for (auto& a: x)

const int MAXN=2e5+5;

int N,M,K;
vector<int> vals(MAXN);
vector<vector<int>> adj(MAXN);

bool cycle=false;
int path[MAXN];
bool vis[MAXN];
bool dfsVis[MAXN];

void dfs(int k,int a){
	vis[k]=true;
	dfsVis[k]=true;
	TRAV(i,adj[k]){
		if(vals[i]>a){
			continue;
		}
		if(dfsVis[i]==true){
			cycle=true;
		}
		if(!vis[i]){
			dfs(i,a);	
		}
		path[k]=max(path[k],path[i]+1);	
	}
	dfsVis[k]=false;
}

bool f(int k){
	fill(begin(path),begin(path)+N,1);
	fill(begin(vis),begin(vis)+N,false);
	fill(begin(dfsVis),begin(dfsVis)+N,false);
	cycle=false;
	FOR0(i,N){
		if(vals[i]>k){continue;}
		if(!vis[i]){
			dfs(i,k);
		}
	}
	if(cycle){
		return true;
	}else{
		int longest=0;
		FOR0(i,N){
			longest=max(longest,path[i]);
		}
		if(longest>=(K)){
			return true;
		}
		return false;
	}

}

int first_true(int lo, int hi) {
	hi++;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (f(mid)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>N>>M>>K;

	FOR0(i,N){
		cin>>vals[i];
	}
	if(M==0 && N==1 && K<=vals[0]){
		cout<<vals[0]<<endl;
		return 0;
	}
	if(M==0 && N==1 && K>vals[0]){
		cout<<-1<<endl;
		return 0;
	}
	FOR0(i,M){
		int a,b; cin>>a>>b;
		a--,b--;
		adj[a].pb(b);
	}
	int ans=first_true(1,1000000000+10);
	if(ans!=(1000000000+11)){
		cout<<ans<<endl;
	}else{
		cout<<-1<<endl;
	}
	return 0;
}
