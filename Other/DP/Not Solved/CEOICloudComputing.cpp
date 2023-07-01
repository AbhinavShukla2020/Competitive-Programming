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
struct transaction{
	int cores;
	int frames;
	int profit;
};

bool cmp(transaction a, transaction b){
	if(a.frames!=b.frames){
		return a.frames>b.frames;
	}else{
		return a.profit<b.profit;
	}
}
int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin>>N;
	int cores=0;
	vector<transaction> transactions;
	FOR0(i,N){
		int a,b,c;
		cin>>a>>b>>c;
		cores+=a;
		transactions.pb({a,b,-c});
	}
	int M;
	cin>>M;
	FOR0(i,M){
		int a,b,c;
		cin>>a>>b>>c;
		transactions.pb({-a,b,c});
	}
	sort(transactions.begin(),transactions.end(),cmp);
	
	vi dp(cores+3);
	FOR1(i,cores){
		dp[i]=-1010000000000000000;
	}
	dp[0]=0;
	int num=1;

	TRAV(i,transactions){
		vi cur(cores+3);
		cur=dp;
		int curCores=i.cores;
		for(int c=0;c<=cores;c++){
			int left=c-i.cores;
			if(left>=0 && left<=cores && dp[left]!=(-1010000000000000000)){
				cur[c]=max(cur[c],dp[left]+i.profit);
			}
		}
		dp=cur;
		num++;
	}

	int ans=0;
	FOR0(i,cores+1){
		ans=max(ans,dp[i]);
	}

	cout<<ans<<endl;
	return 0;
}
