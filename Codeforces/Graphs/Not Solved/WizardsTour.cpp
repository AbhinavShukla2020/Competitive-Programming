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

const ll MAXN=2e5+1;
ll N,M;
vector<vl> adj(MAXN);
bool vis[MAXN];
vector<vl> ans;

bool dfs(ll a, ll prev){
	vis[a]=true;
	vl cur;
	for(ll i : adj[a]){
		if(i==prev){continue;}
		if(vis[i]){
			if(i>a){
				cur.pb(i);
			}
		}else if(!dfs(i,a)){
			cur.pb(i);
		}
	}
	
	if(cur.size()%2==1 && prev!=-1){
		ans.pb({cur[cur.size()-1],a,prev});
	}

	FOR0(i,cur.size()/2){
		ans.pb({cur[2*i],a,cur[2*i+1]});
	}
	
	if(cur.size()%2==0){
		return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>M;
	FOR1(i,M){
		ll a,b;
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	FOR1(i,N){
		if(!vis[i]){
			dfs(i,-1);
		}
	}

	cout<<ans.size()<<endl;
	TRAV(i,ans){
		TRAV(j,i){
			cout<<j<<" ";
		}
		cout<<endl;
	}
	return 0;
}
