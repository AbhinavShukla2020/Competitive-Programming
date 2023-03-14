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

struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

	// get representive component (uses path compression)
	int get(int x) { return e[x] < 0 ? x : get(e[x]); }

	bool same_set(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x; return true;
	}
};

int32_t main(){
	fileIO("mootube");
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N,Q;
	cin>>N>>Q;
	vector<pair<int,pii>> edges;
	FOR0(i,N-1){
		int a,b,c;
		cin>>a>>b>>c;
		edges.pb({c,{a,b}});
	}
	sort(edges.begin(),edges.end(),greater<pair<int,pii>>());

	int ind=0;
	DSU dsu(N+1);

	vector<pii> queries;
	vector<pii> orig;
	FOR0(i,Q){
		int a,b;
		cin>>a>>b;
		queries.pb({a,b});
		orig.pb({a,b});
	}
	
	sort(queries.begin(),queries.end(),greater<pii>());

	map<pii,int> ans;
	TRAV(i,queries){
		while(ind<N-1 && edges[ind].first>=i.first){
			dsu.unite(edges[ind].second.first,edges[ind].second.second);
			ind++;
		}
		ans[i]=dsu.size(i.second)-1;

	}

	TRAV(i,orig){
		cout<<ans[i]<<endl;
	}
	


	return 0;
}
