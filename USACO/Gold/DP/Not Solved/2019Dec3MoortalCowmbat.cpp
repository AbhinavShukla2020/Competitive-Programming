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

int32_t main(){
	freopen("cowmbat.in", "r", stdin);
  	freopen("cowmbat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N,M,K;
	cin>>N>>M>>K;
	string s;
	cin>>s;
	int in[M+1][M+1];
	FOR0(i,M){
		FOR0(j,M){
			cin>>in[i][j];
		}
	}

	for (int k = 0; k < M; k++) {
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < M; j++) {
				in[i][j] = min(in[i][j], in[i][k] + in[k][j]);
			}
		}
	}

	int pref[N+1][M];
	for(int i=0;i<N;i++){
		pref[0][i]=0;
	}
	for(int i=1;i<=N;i++){
		for(int j=0;j<M;j++){
			pref[i][j]=pref[i-1][j]+in[s[i-1]-'a'][j];
		}
	}

	int dp[N+1][26];
	for(int i=0;i<=N;i++){
		for(int j=0;j<26;j++){
			if(i==0){
				dp[i][j]=0;
				continue;
			}
			dp[i][j]=1000000000000;
		}
	}
	for(int i=K;i<=N;i++){
		for(int j=0;j<M;j++){
			dp[i][j]=min(dp[i][j],dp[i-1][j]+in[s[i-1]-'a'][j]);
			for(int c=0;c<M;c++){
				dp[i][j]=min(dp[i][j],pref[i][j]-pref[i-K][j]+dp[i-K][c]);
			}
		}
	}

	int ans=100000000000;
	FOR0(i,M){
		ans=min(ans,dp[N][i]);
	}
	cout<<ans<<endl;




	return 0;
}
