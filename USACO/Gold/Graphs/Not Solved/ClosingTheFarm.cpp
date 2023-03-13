#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <cassert>
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

void fileIO(string filename) {
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}

vector<vector<int>> adj;
struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

	// get representive component (uses path compression)
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool get2(int x, int orig){
		if(x==orig){
			return true;
		}
		if(e[x]<0){
			return false;
		}
		return get2(e[x],orig);
	}
	bool same_set(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	void unite(int x, int y) {  // union by size
		x = get(x), y = get(y);
		if(x==y){
			return;
		}
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x; 
	}


};

int32_t main(){
	fileIO("closing");
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N,M;
	cin>>N>>M;
	vector<vector<int>> adj(N+1);
	FOR0(i,M){
		int a,b;
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	vector<int> order;
	FOR0(i,N){
		int a;
		cin>>a;
		order.pb(a);
	}
	
	vector<bool> in(N+1,false);
	set<int> curIn;
	DSU dsu(N+1);
	int ans[N+1];
	for(int i=N-1;i>=0;i--){
		int cur=order[i];
		in[cur]=true;
		TRAV(j,adj[cur]){
			if(in[j]){
				dsu.unite(cur,j);
			}
		}
		if(dsu.size(cur)==N-i){
			ans[i]=1;
		}else{
			ans[i]=0;
		}

	}
	FOR0(i,N){
		cout<< (ans[i]<1 ? "NO" : "YES")<<endl;
	}


	return 0;
}
