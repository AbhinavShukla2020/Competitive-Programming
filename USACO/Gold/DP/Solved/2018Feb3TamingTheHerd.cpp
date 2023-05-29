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

int max(int a,int b){
	if(a>b){
		return a;
	}
	return b;
}

int dp[101+1][101+1];

void fileIO(string filename) {
  freopen((filename + ".in").c_str(), "r", stdin);
  freopen((filename + ".out").c_str(), "w", stdout);
}

int32_t main() {
	fileIO("taming");
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin>>N;
	vi in(N+1);
	FOR1(i,N){
		cin>>in[i];
	}


	//int dp[N+1][N+1];
	int cnt=0;
	dp[1][0]=100000000000000;
	FOR1(i,N){
		if(in[i]!=(i-1)){
			cnt++;
		}
		dp[1][i]=cnt;
	}

	FOR(i,2,N+1){
		dp[i][0]=1000000000000000;
		FOR1(j,N){
			if(j<i){
				dp[i][j]=100000000000000;
				continue;
			}
			
			dp[i][j]=min(dp[i-1][j-1]+1,dp[i][j-1]+1);
			int start=j-in[j];
			
			if(start>=1){
				int cur=0;
				int tot=0;
				while(cur!=in[j]){
					if(cur!=in[start]){
						tot++;
					}
					cur++;
					start++;
				}
				
				dp[i][j]=min(dp[i][j],dp[i-1][j-in[j]-1]+tot);
			}
		}
	}


	FOR1(i,N){
		cout<<dp[i][N]<<endl;
	}


	return 0;
}
