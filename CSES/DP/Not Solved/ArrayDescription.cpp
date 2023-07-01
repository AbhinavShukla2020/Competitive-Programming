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

const int MOD=1000000007;
int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N,M;
	cin>>N>>M;
	vi in(N+1);
	FOR1(i,N){
		cin>>in[i];
	}
	int ans=0;
	vector<vector<int>> dp(N+1,vector<int>(M+1,0));
	dp[0][0]=1;
	FOR1(i,N){
		if(in[i]==0){
			if(i==1){
				FOR0(j,M+1){
					dp[i][j]=1;
				}
				continue;
			}
			FOR0(j,M+1){
				dp[i][j]+=dp[i-1][j];
				if((j-1)>=1){
					dp[i][j]+=dp[i-1][j-1];
				}
				if((j+1)<=M){
					dp[i][j]+=dp[i-1][j+1];
				}
				dp[i][j]%=(MOD);
			}

		}else{
			if(i==1){
				dp[i][in[i]]=1;
			}else{
				dp[i][in[i]]+=dp[i-1][in[i]];
				if((in[i]-1)>=1){
					dp[i][in[i]]+=dp[i-1][in[i]-1];
				}
				if((in[i]+1)<=M){
					dp[i][in[i]]+=dp[i-1][in[i]+1];
				}
				dp[i][in[i]]%=(MOD);
			}
		}
	}
	// FOR0(i,N+1){
	// 	FOR0(j,M+1){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	FOR1(i,M){
		ans+=dp[N][i];
		ans%=MOD;
	}
	cout<<ans<<endl;



	return 0;
}
