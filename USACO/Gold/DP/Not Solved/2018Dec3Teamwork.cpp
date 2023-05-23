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
  	fileIO("teamwork");
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N,K;
	cin>>N>>K;
	vi in(N+1);
	FOR1(i,N){
		cin>>in[i];
	}

	int dp[N+1];
	FOR0(i,N+1){
		dp[i]=0;
	}

	FOR1(i,N){
		int curBest=in[i];
		for(int j=i;j>=max(1,(i-K+1));j--){
			curBest=max(curBest,in[j]);
			dp[i]=max(dp[i],dp[j-1]+curBest*(i-j+1));
		}
		
	}
	cout<<dp[N]<<endl;
	


	return 0;
}
