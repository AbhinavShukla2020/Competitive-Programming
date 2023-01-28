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
		int n,s,r;
		cin>>n>>s>>r;
		vector<int> die;
		FOR0(i,n-1){
			die.pb(s-r);
		}
		die.pb(s-r);
		while(true){
			// //int curMax=0;
			// TRAV(i,die){
			// //	cout<<i<<" ";
			// }
			// cout<<endl;
			int curSum=0;
			FOR0(i,n-1){
			//	curMax=max(curMax,die[i]);
				curSum+=die[i];
			}
			if(curSum==r){
				break;
			}
			FOR0(i,n-1){
				if(die[i]==1){
					continue;
				}
				die[i]--;
				curSum--;
				if(curSum==r){
					break;
				}
			}
		}
		TRAV(i,die){
			cout<<i<<" ";
		}
		cout<<endl;
	}


	return 0;
}
