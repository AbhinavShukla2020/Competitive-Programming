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

int dp[401][401];

int max(int a,int b){
	if(a>b){
		return a;
	}
	return b;
}

void fileIO(string filename) {
  freopen((filename + ".in").c_str(), "r", stdin);
  freopen((filename + ".out").c_str(), "w", stdout);
}

int32_t main() {
  	fileIO("snakes");
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N,K;
	cin>>N>>K;
	vi in(N+1);
	FOR1(i,N){
		cin>>in[i];
	}
	int ans=1000000000000000;
	int cur=in[1];
	int curSum=0;
	FOR1(j,N){
		curSum+=in[j];
		cur=max(cur,in[j]);
		dp[0][j]=j*cur-curSum;
	}
	FOR1(i,K){
		FOR1(j,N){
			dp[i][j]=10000000000000;
		}
	}
	FOR1(i,K){
		FOR1(j,N){
			int curMax=in[j];
			int curSum=0;
			for(int k=j;k>=1;k--){
				curMax=max(curMax,in[k]);
				curSum+=in[k];
				dp[i][j]=min(dp[i][j],dp[i-1][k-1]+((j-k+1)*curMax-curSum));
			}
			if(j==N){
				ans=min(dp[i][j],ans);
			}
		}

	}
	cout<<ans<<endl;

	return 0;
}
