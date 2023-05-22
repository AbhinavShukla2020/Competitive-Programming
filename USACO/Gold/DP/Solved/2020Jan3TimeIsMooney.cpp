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


#define endl "\n"
#define int int64_t 
#define pb push_back
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR0(i,a) FOR(i,0,a)
#define FOR1(i,a) for (int i = (1); i <= (a); ++i)
#define TRAV(a,x) for (auto& a: x)

 
using pii = pair<int,int>;
using vi = vector<int>;


void fileIO(string filename) {
  freopen((filename + ".in").c_str(), "r", stdin);
  freopen((filename + ".out").c_str(), "w", stdout);
}


int32_t main(){
	fileIO("time");
        int N,M,C;
	vi in;
	vector<vector<int>> adj;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>N>>M>>C;
	adj.resize(N+10);

	FOR0(i,N){
		int a;
		cin>>a;
		in.pb(a);
	}

	FOR0(i,M){
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		adj[a].pb(b);
	}

	int dp[1012][1011];
	FOR0(i,1002){
		FOR0(j,1001){
			dp[i][j]=-1;
		}
	}

	dp[0][0]=0;
	int ans=0;
	FOR1(t,1001){
		FOR0(i,N){
			TRAV(j,adj[i]){
				if(dp[j][t-1]!=-1){
					dp[i][t]=max(dp[i][t],dp[j][t-1]+in[i]);
				}
			}
		}
		ans=max(ans,dp[0][t]-C*(t)*(t));
	}
	cout<<ans<<endl;
	

	return 0;
}
