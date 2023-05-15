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
	int S,N;
	cin>>S>>N;
	map<int,vector<pii>> items;
	FOR0(i,N){
		int value,weight,amt;
		cin >> value >> weight >> amt;
		if (weight <= S && amt > 0) {
			items[weight].push_back({value, amt});
		}
	}
	TRAV(i,items){
		sort(i.second.begin(),i.second.end(),greater<pii>());
	}

	//dp[first i items][j weight allowed]
	vector<vector<int>> dp(items.size()+1,vector<int>(S+1,-100));
	

	dp[0][0]=0;
	int at=1;

	TRAV(i,items){
		int w=i.first;
		vector<pii> item=i.second;
		FOR0(j,S+1){
			dp[at][j]=dp[at-1][j];
			int used=0;
			int type=0;
			int curTypeUsed=0;
			int profit=0;
			while((w*(used+1))<=j && type<item.size()){
				used++;
				curTypeUsed++;
				profit+=item[type].first;
				if(dp[at-1][j-used*w]!=-100){
					dp[at][j]=max(dp[at][j],dp[at-1][j-used*w]+profit);
				}
				if(item[type].second==curTypeUsed){
					type++;
					curTypeUsed=0;
				}
			}
		}

		at++;
	}
	
	int ans=-1;
	TRAV(i,dp[dp.size()-1]){
		ans=max(ans,i);
	}
	cout<<ans<<endl;

	return 0;
}
