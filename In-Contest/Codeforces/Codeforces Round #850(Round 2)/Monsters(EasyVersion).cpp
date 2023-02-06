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
		int N;
		cin>>N;
		vector<int> mon(N);
		map<int,int> occ;
		FOR0(i,N){
			cin>>mon[i];
			occ[mon[i]]++;
		}
		sort(mon.begin(),mon.end());
		int cnt=1;
		int ans=0;
		TRAV(i,mon){
			if(i==cnt-1){
				continue;
			}
			if(i==cnt){
				cnt++;
				continue;
			}
			if(i>cnt){
				ans+=(i-cnt);
			}
			cnt++;
		}
		cout<<ans<<endl;

	}


	return 0;
}
