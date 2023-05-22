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



int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--){
		int N;
		cin>>N;
		vi in(N);
		FOR0(i,N){
			cin>>in[i];
		}
		if(N==1){
			cout<<in[0]<<endl;
			continue;
		}
		int dp[N+5][2];
		dp[0][0]=0;
		dp[0][1]=0;
		dp[1][1]=1;
		FOR1(i,N){
			if(i>2){
				dp[i][1]=dp[i-1][0];
				if(i>1){
					dp[i][1]=min(dp[i][1],dp[i-2][0]);
				}
			}
			if(i==2){
				dp[i][1]=dp[i-1][0];
			}
			if(in[i-1]==1){
				if(i!=1){
					dp[i][0]=dp[i-1][1]+1;
				}else{
					dp[i][0]=in[i-1];
				}
				if(i>1){
					if(in[i-2]==1){
						dp[i][0]=min(dp[i][0],dp[i-2][1]+2);
					}else{
						dp[i][0]=min(dp[i][0],dp[i-2][1]+1);
					}
				}
			}else{
				dp[i][0]=dp[i-1][1];
				if(i>1){
					if(in[i-2]==1){
						dp[i][0]=min(dp[i][0],dp[i-2][1]+1);
					}else{
						dp[i][0]=min(dp[i][0],dp[i-2][1]);
					}
				}
			}
		}
		cout<<min(dp[N][0],dp[N][1])<<endl;
	}


	return 0;
}
