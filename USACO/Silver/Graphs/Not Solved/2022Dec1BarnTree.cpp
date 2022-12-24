#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;

using ll = long long;
using pii = pair<ll,ll>;
const ll MAXN=2e5+1;

vector<vector<ll>> ans;
vector<vector<ll>> adj(MAXN);
vector<vector<ll>> children(MAXN);
vector<ll> bales(MAXN);
map<ll,ll> parent;
bool vis[MAXN];
bool vis2[MAXN];
ll desired=0;
vector<ll> subTreeSize(MAXN);
vector<ll> subTreeSum(MAXN);
void getParents(ll a){
	vis2[a]=true;
	if(adj[a].size()==1){
		subTreeSize[a]=1;
		subTreeSum[a]=bales[a];
	}else{
		subTreeSize[a]++;
		subTreeSum[a]+=bales[a];
	}
	for(ll k : adj[a]){
		if(!vis2[k]){
			parent[k]=a;
			getParents(k);
			subTreeSize[a]+=subTreeSize[k];
			subTreeSum[a]+=subTreeSum[k];
		}
	}
}
void dfs(ll a){
	for(ll k : adj[a]){
		if(parent[a]!=k){
			dfs(k);
		}
		
	}
	for(ll k : adj[a]){
		if(parent[a]==k){continue;}
		if((desired*subTreeSize[k]-subTreeSum[k])<0){
			ans.push_back({k,a,subTreeSum[k]-desired*subTreeSize[k]});
			bales[a]+=(bales[k]-desired*subTreeSize[k]);
			bales[k]=desired*subTreeSize[k];
		}
	}
	


}
void dfs3(ll a){
	for(ll k : adj[a]){
		if(parent[a]==k){continue;}
		if(0<(desired*subTreeSize[k]-subTreeSum[k])){
			ans.push_back({a,k,desired*subTreeSize[k]-subTreeSum[k]});
		
			bales[a]-=(desired*subTreeSize[k]-subTreeSum[k]);
			bales[k]=desired*subTreeSize[k];
		}
	}
	for(ll k : adj[a]){
		if(parent[a]==k){continue;}
		dfs3(k);
	}
}
int main(){

	for(ll i=0;i<MAXN;i++){
		vis[i]=false;
		subTreeSize[i]=0;
		subTreeSum[i]=0;
	}
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N;
	cin>>N;
	for(ll i=1;i<=N;i++){
		cin>>bales[i];
		desired+=bales[i];
	}
	desired/=N;
	for(ll i=0;i<N-1;i++){
		ll a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	getParents(1);
	dfs(1);
	dfs3(1);
	cout<<ans.size()<<endl;
	int counter2=0;
	for(vector<ll> i : ans){
		int counter=0;
		for(ll k : i){
			if(counter!=2){
				cout<<k<<" ";
			}else{
				cout<<k;
			}
			counter++;
		}
		if(counter2!=ans.size()-1){
			cout<<endl;
		}
		counter2++;
	}



	return 0;
}
