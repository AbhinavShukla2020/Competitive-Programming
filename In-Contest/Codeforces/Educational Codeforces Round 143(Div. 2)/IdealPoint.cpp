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
		int N,K;
		cin>>N>>K;
		vector<pii> intervals;
		FOR0(i,N){
			int a,b;
			cin>>a>>b;
			if(a<=K && K<=b){
				intervals.pb({a,b});
			}
		}
		int vals[51];
		vals[0]=-1;
		FOR1(i,50){
			vals[i]=0;
			TRAV(j,intervals){
				if(i>=j.first && i<=j.second){
					vals[i]++;
				}
			}
		//	cout<<i<<" "<<vals[i]<<endl;
		}
		int k=vals[K];
		bool ans=true;
		FOR1(i,50){
			if(i==K){continue;}
			if(vals[i]>=k){
				ans=false;
			}
		}
		if(ans){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}


	return 0;
}
