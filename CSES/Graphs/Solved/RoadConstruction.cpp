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

int sizeCC=1;
int max(int a, int b){
	if(a>b){
		return a;
	}
	return b;
}
struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

	// get representive component (uses path compression)
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N,M;
	cin>>N>>M;
	
	DSU dsu(N);
	int ccs=N;
	FOR0(i,M){
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		if(!dsu.same_set(a,b)){
			ccs--;
		}
		dsu.unite(a,b);
		sizeCC=max(sizeCC,max(dsu.size(a),dsu.size(b)));
		cout<<ccs<<" "<<sizeCC<<endl;
	}


	return 0;
}
