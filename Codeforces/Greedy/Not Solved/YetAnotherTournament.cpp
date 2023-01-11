#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <unordered_set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
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
		int N,M;
		cin>>N>>M;
		vector<int> wins(N+1,0);
		vector<int> nums(N+1,0);
		vector<pii> cost;
		FOR0(i,N){
			cin>>nums[i+1];
			cost.pb({nums[i+1],i+1});
			wins[i+1]=i+1;
		}
		sort(cost.begin(),cost.end());
		vector<int> used;
		int curWon=0;
		int curSpent=0;
		vector<bool> use(N+1,false);
		TRAV(i,cost) if((curSpent+i.first)<=M){
			curSpent+=i.first;
			used.pb(i.first);
			use[i.second]=true;
			curWon++;
			wins[i.second]--;
		}
		int ans=1;
		FOR1(i,N) if(wins[i]>curWon){
			ans++;
		}
		sort(used.begin(),used.end(),greater<int>());
		if(ans!=1 && !use[N-ans+2] && used.size()!=0){
			if((curWon+1)==wins[N-ans+2] && (curSpent-used[0].first+nums[N-ans+2])<=M){
				ans--;
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}
