/*
2021 Gold December Problem 1 Paired Up

We can split the cows into chains where a chain is a list of cows such that every 2 adjacent
cows are within K distance of each other. Every cow is in exactly one chain clearly.

We need to make 2 obervations.

1. There can be no 2 unpaired cows within K distance of each other.
2. Every chain must have an even number of paired cows. This means that we can only unpair
	a cow if there are currently an odd number of paired cows.

We can then split the problem into 2 cases.
Case 1: T=1(minimize sum)


Case 2: T=2(maximize sum)
Let dp[i][j] be the maximum sum of unpaired cows given we only can use the last i cows
and j of them are unpaired.
If we leave the ith cow paired, then dp[i][j]=dp[i+1][j]
If we want to unpair ith cow then we need that the remaining cows either form
	1. 2 seperate chains of even length
	1. 1 chain of odd length

Then, all of the cows between i and ub[i] must be paired by obervation 1. This gives the transition.
*/



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

const int INF=100000000000000;
int T,N,K;
int solve1(vector<pii> chain){
	int n=chain.size();
	if((n%2)==0){
		return 0;
	}
	int ans=INF;
	FOR0(i,n){
		if((i%2)==0 || ((chain[i+1].first-chain[i-1].first)<=K)){
			ans=min(ans,chain[i].second);
		}
	}
	return ans;
}

int solve2(vector<pii> chain){
	if(chain.empty()){return 0;}
	int n=chain.size();
	int dp[n+1][2]; 
	FOR0(i,n+1){
		dp[i][0]=0;
		dp[i][1]=0;
	}
	dp[n][0]=0;
	dp[n][1]=-1000000000;
	for(int i=(n-1);i>=0;i--){
		dp[i][0]=dp[i+1][0];
		dp[i][1]=dp[i+1][1];
		int next=upper_bound(chain.begin(), chain.end(),
                             make_pair(chain[i].first + K, INF)) -
                 chain.begin();
        if(i!=0 && i!=(n-1)){
     	   assert((chain[i+1].first-chain[i-1].first)>=0);
    	}
        if(i==0 || i==(n-1) || ((chain[i+1].first-chain[i-1].first)<=K) || (n-i)%2==0){
        	dp[i][0]=max(dp[i][0],dp[next][1]+chain[i].second);
        }
        if(i==0 || i==(n-1) || (chain[i+1].first-chain[i-1].first)<=K || (n-i)%2==1){
        	dp[i][1]=max(dp[i][1],dp[next][0]+chain[i].second);
        }
	}
	if((n%2)==0){
		return dp[0][0];
	}
	return dp[0][1];
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T>>N>>K;
	int prev=-1;
	vector<pii> cur;
	int ans=0;
	FOR0(i,N){
		int a,b;
		cin>>a>>b;
		if(prev==(-1) || (a-prev)<=K){
			cur.pb({a,b});
			prev=a;
		}else{
			if(T==1){
				ans+=solve1(cur);
			}else{
				ans+=solve2(cur);
			}
			cur.clear();
			cur.pb({a,b});
			prev=a;
		}
	}
	if(T==1){
		ans+=solve1(cur);
	}else{
		ans+=solve2(cur);
	}
	cout<<ans<<endl;



	return 0;
}
