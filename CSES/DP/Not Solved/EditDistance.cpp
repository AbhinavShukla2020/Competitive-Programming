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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string a1;
	string b1;
	cin>>a1>>b1;
	string a,b;
	a.pb('.');
	b.pb('.');
	int n=a1.size(),m=b1.size();
	FOR0(i,n){
		a.pb(a1[i]);
	}
	FOR0(j,m){
		b.pb(b1[j]);
	}
 
	int dp[n+1][m+1];
	FOR0(i,n+1){
		FOR0(j,m+1){
			dp[i][j]=10000000000;
		}
	}
	dp[0][0]=0;
	FOR1(i,n){
		FOR1(j,m){
			if(i!=0 && j!=0 && a.at(i)==b.at(j)){
				dp[i][j]=min(dp[i-1][j-1],dp[i][j]);
			}
			if(i!=0 && j!=0 && a.at(i)!=b.at(j)){
				dp[i][j]=min(dp[i-1][j-1]+1,dp[i][j]);
			}
			if(i!=0){
				dp[i][j]=min(dp[i-1][j]+1,dp[i][j]);
			}
			if(j!=0){
				dp[i][j]=min(dp[i][j-1]+1,dp[i][j]);
			}
		}
	}
	// FOR0(i,n+1){
	// 	FOR0(j,m+1){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	cout<<dp[n][m]<<endl;
 
 
	return 0;
}
