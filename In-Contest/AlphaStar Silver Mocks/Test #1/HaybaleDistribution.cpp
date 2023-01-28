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

const int MAXN=1000000;
vector<int> cow;
vector<vector<int>> adj;
int down[MAXN];
int subTreeSum[MAXN];

int dfs(int a,int p){
	//cout<<a<<endl;
	subTreeSum[a]=0;
	down[a]=0;
	int cur=cow[a];
	TRAV(i,adj[a]){
		if(i==p){continue;}
		dfs(i,a);
		cur+=subTreeSum[i];
		down[a]=max(down[a],subTreeSum[i]);
	}
	subTreeSum[a]=cur;
	return cur;
}


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin>>N;
	
	int tot=0;
	FOR0(i,N){
		int a;
		cin>>a;
		cow.pb(a);
		tot+=a;
	}

	adj.resize(N);
	FOR0(i,N-1){
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(0,-1);
	//cout<<endl<<endl<<endl<<endl;
	set<int> best;
	int numBest=100000999000000;
	FOR0(i,N){
		if(down[i]==0){
			down[i]=-1;
		}
		//cout<<i+1<<" "<<down[i]<<" "<<subTreeSum[i]<<endl;
		int curBest=max(down[i],tot-subTreeSum[i]);
		if(numBest>curBest){
			best.clear();
			best.insert(i+1);
			numBest=curBest;
		}else if(numBest==curBest){
			best.insert(i+1);
		}
	}
	TRAV(i,best){
		cout<<i<<" ";
	}








	return 0;
}
