#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;

using ll = long long;
using pii = pair<ll,ll>;

const ll MAXN=1e6+5;

ll adj[MAXN];
map<pii,ll> edges;
bool vis[MAXN];
unordered_set<ll> path;
vector<vector<ll>> cycles;

void dfs(ll a){
	vis[a]=true;
	path.insert(a);

	if(path.count(adj[a])){
		ll u=a;
		ll v=adj[a];
		vector<ll> curCycle;
		curCycle.push_back(u);
		while(v!=u){
			curCycle.push_back(v);
			v=adj[v];
		}
		cycles.push_back(curCycle);
	}else if(!vis[adj[a]]){
		dfs(adj[a]);
	}
}

int main(){
	for(int i=0;i<MAXN;i++){
		vis[i]=false;
	}
	
	ll N;
	cin>>N;
	ll ans=0;
	for(ll i=1;i<=N;i++){
		cin>>adj[i];
		ll weight;
		cin>>weight;
		edges[{i,adj[i]}]=weight;
		ans+=weight;
	}

	for(ll i=1;i<=N;i++){
		if(!vis[i]){
			path.clear();
			dfs(i);
		}
		
	}

	for(vector<ll> i : cycles){
			ll minWeight=LLONG_MAX;
			for(ll j=0;j<i.size()-1;j++){
				minWeight=min(minWeight,edges[{i[j],i[j+1]}]);
			}
			
			ans-=minWeight;
	}
	cout<<ans<<endl;

}