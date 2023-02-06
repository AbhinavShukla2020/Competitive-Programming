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
		int N,W,H;
		cin>>N>>W>>H;
		vector<int> cake(N);
		vector<int> dis(N);
		FOR0(i,N){
			cin>>cake[i];
		}
		FOR0(i,N){
			cin>>dis[i];
		}
		if(H>W){
			cout<<"NO"<<endl;
			continue;
		}
		int curMin=-100000000000000000;
		int curMax=1000000000000000000;
		bool works=true;
		FOR0(i,N){
			int cakeL=cake[i]-W;
			int cakeU=cake[i]+W;
			int disL=cakeL+H;
			int disU=cakeU-H;
			int shiftLow=min(dis[i]-disU,dis[i]-disL);
			int shiftHigh=max(dis[i]-disU,dis[i]-disL);
			//cout<<shiftLow<<" "<<shiftHigh<<endl;
			if(shiftLow>curMax){
				works=false;
				break;
			}
			if(shiftHigh<curMin){
				works=false;
				break;
			}
			curMin=max(curMin,shiftLow);
			curMax=min(curMax,shiftHigh);

		}
		if(works){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}


	return 0;
}
