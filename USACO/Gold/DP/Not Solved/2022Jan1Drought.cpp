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

const int MOD=1e9+7;
int N;
vi in;
int even(){
	int dp[N+1][2001];
	FOR0(i,N+1){
		FOR0(j,2001){
			dp[i][j]=0;
		}
	}
	int pref[1000+1];
	for(int i=0;i<=in[1];i++){
		pref[i]=i+1;
	}
	for(int i=(in[1]+1);i<=1000;i++){
		pref[i]=in[1]+1;
	}
	for(int i=2;i<=N;i++){
		for(int j=0;j<=in[i];j++){
			dp[i][j]=pref[in[i]-j];
			dp[i][j]%=MOD;
		}
		pref[0]=dp[i][0];
		pref[0]%=MOD;
		for(int j=1;j<=1000;j++){
			pref[j]=pref[j-1]+dp[i][j];
			pref[j]%=MOD;
		}
	}
	return dp[N][0];
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N;
	in.resize(N+1);
	int small=10000000;
	FOR1(i,N){
		cin>>in[i];
		small=min(in[i],small);
	}
	if(N%2==0){
		cout<<even();
	}else{
		int ans=0;
		for(int i=0;i<=small;i++){
			ans+=even();
			ans%=MOD;
			FOR1(j,N){
				in[j]--;
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}
