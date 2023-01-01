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

const int MAXN=1e5+1;
bool vis[MAXN+1];
bool self=false;
ll curSize=0;
ll numEdges=0;

void dfs(int cur,vector<vi>& adj){
	curSize++;
	vis[cur]=true;
	for(int i : adj[cur]){
		numEdges++;
		if(i==cur){self=true;}
		if(vis[i]){
		}
		if(!vis[i]){
			dfs(i,adj);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	FOR0(t,T){
		int N;
		cin>>N;
		vector<pii> nums(N);
		vector<vector<int>> adj(N+1);
		FOR0(i,N){
			cin>>nums[i].first;
		}
		FOR0(i,N){
			cin>>nums[i].second;
			if(nums[i].first!=nums[i].second){
				adj[nums[i].first].pb(nums[i].second);
				adj[nums[i].second].pb(nums[i].first);
			}else{
				adj[nums[i].first].pb(nums[i].first);
			}
			vis[i+1]=false;
		}

		ll ans=1;
		FOR1(i,N){
			curSize=0;
			numEdges=0;
			self=false;
			if(!vis[i]){
				dfs(i,adj);
				if(self){
					numEdges++;
				}
				if(numEdges/2!=curSize){
					ans=0;
					break;
				}
				if(self){
					ans*=N;
					ans%=998244353;
				}else{
					ans*=2;
					ans%=998244353;
				}
			}
		}
		cout<<ans<<endl;

	}


	return 0;
}
