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

int N,M;
vector<vector<int>> grid(N);
vector<int> height;
vector<int> neighbors[1000000];
int maxpeakh[1000000]; //Max height of all peaks in this component
vector<int> mypeaks[1000000]; 
int ans[1000000];

struct DSU {
	vector<int> e;
	DSU(int N,int M) { e = vector<int>(N*M, -1); }

	// get representive component (uses path compression)
	int get(int x) { return e[x] < 0 ? x : get(e[x]); }

	bool same_set(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y, int cur) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x]>e[y]) swap(x, y);

		if(maxpeakh[x]>maxpeakh[y]){
			TRAV(i,mypeaks[y]){
				ans[i]=cur;
			}
			// maxpeakh[y]=maxpeakh[x];
			// mypeaks[y].clear();
		}else if(maxpeakh[x]<maxpeakh[y]){
			TRAV(i,mypeaks[x]){
				ans[i]=cur;
			}
			maxpeakh[x]=maxpeakh[y];
			mypeaks[x]=mypeaks[y];
		}else{
            TRAV(j,mypeaks[y]){
                mypeaks[x].pb(j);
            }
		}
		e[x] += e[y]; e[y] = x; return true;

	}
};


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>N>>M;
	height.resize(N*M);
	vector<pii> sorted;
	FOR0(i,N*M){
		cin>>height[i];
		sorted.pb({height[i],i});
	}
	sort(sorted.begin(),sorted.end(),greater<pii>());
	bool added[N*M+1];

	for (int i = 0; i < N * M; i++) {
		added[i]=false;
		if (i % M != 0) neighbors[i].push_back(i - 1);
		if (i % M != M - 1) neighbors[i].push_back(i + 1);
		if (i - M >= 0) neighbors[i].push_back(i - M);
		if (i + M < N * M) neighbors[i].push_back(i + M);
		mypeaks[i].push_back(i);
		maxpeakh[i] = height[i];
	}
	
	DSU dsu(N+1,M+1);
	TRAV(i,sorted){
		added[i.second]=true;
		TRAV(j,neighbors[i.second]){
			if(added[j]){
				dsu.unite(i.second,j,i.first);
			}
		}
	}

	for (int i = 0; i < N * M; i++) {
		cout << height[i]-ans[i] << ((i % M == (M - 1)) ? "\n" : " ");
	}






	return 0;
}
