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
		vector<int> nums[N];
		map<int,int> vis;
		

		FOR0(i,N){
			nums[i]={};
			int k;
			cin>>k;
			FOR0(j,k){
				int a;
				cin>>a;
				nums[i].pb(a);
				vis[a]++;
			}
		}
		//cout<<vis[1]<<" "<<vis[2]<<endl;
		bool works=false;
		FOR0(i,N){
			bool curWorks=true;
			TRAV(k,nums[i]){
				if(vis[k]<2){
					curWorks=false;
					break;
				}
			}
			if(curWorks){
				works=true;
				break;
			}
		}
		if(works){
			cout<<"yes"<<endl;
		}else{
			cout<<"no"<<endl;
		}
	}


	return 0;
}
