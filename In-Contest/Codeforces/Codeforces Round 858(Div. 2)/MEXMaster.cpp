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

int min(int a,int b){
	if(a<b){
		return a;
	}
	return b;
}
int getAns(int N,vi ans){
	vi ans3=ans;
	set<int> sums;
	FOR0(i,N-1){
			sums.insert(ans3[i]+ans3[i+1]);
	}
	//sort(sums.begin(),sums.end());
	// TRAV(i,sums){
	// 	cout<<i<<" ";
	// }
	// cout<<endl;
	if(*sums.begin()!=0){
			return 0;
	}else{
			
			int cur=-100;
			int ans2=-2;
			TRAV(i,sums){
				if(cur<0){
					cur=i;
				}else{
				//	cout<<i<<" "<<cur<<endl;
					if(i!=(cur+1)){
						ans2=cur+1;
						break;
					}
				}
				cur=i;
			}
			//cout<<"ans2: "<<ans2<<endl;
			if(ans2==-2){
				ans2=*sums.rbegin()+1;
			}
			return ans2;
		}
		
}
int32_t main(){
	//cout<<getAns(4,{1,0,0,0})<<endl;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--){
		int N;
		cin>>N;
		vi in;
		FOR0(i,N){
			int a;
			cin>>a;
			in.pb(a);
		}
		sort(in.begin(),in.end());
		int low=0;
		int high=N-1;
		bool lowOrhigh=false;
		vi ans;
		while(low!=high){
			if(!lowOrhigh){
				ans.pb(in[low]);
				low++;
				lowOrhigh=true;
			}else{
				ans.pb(in[high]);
				high--;
				lowOrhigh=false;
			}
		}
		ans.pb(in[high]);
		// TRAV(u,ans){
		// 	cout<<u<<" ";
		// }
		// cout<<endl;
		int ans2=getAns(N,ans);
		//cout<<ans2<<endl;
		vi non,zeros;
		TRAV(i,in){
			if(i==0){
				zeros.pb(i);
			}else{
				non.pb(i);
			}
		}
		sort(non.begin(),non.end());
		TRAV(i,zeros){
			non.pb(i);
		}
		// TRAV(j,non){
		// 	cout<<j<<" ";
		// }
		// cout<<endl;
		// cout<<getAns(N,non)<<endl;
		//cout<<getAns(N,non)<<endl;
		cout<<min(ans2,getAns(N,non))<<endl;

		
		
		
		//cout<<sums[0]-1<<endl;
	}


	return 0;
}
