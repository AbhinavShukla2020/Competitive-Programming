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

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--){
		int N;
		cin>>N;
		vi in(N);

		map<int,int> occ;
		FOR1(i,N){
			occ[i]=0;
		}
		//set<int> occ;
		int gaps=0;
		vi bad;
		int last=0;
		FOR0(i,N-1){
			cin>>in[i];
			int cur=in[i]-last;
			if(cur>N || cur==0){
				bad.pb(cur);
			}
			if(occ[cur]>=1){
				bad.pb(cur);
			}else{
				occ[cur]=1;
			}
			last=in[i];
		}
		if(bad.size()>1){
			cout<<"NO"<<endl;
		}else if(bad.size()==0){
			cout<<"YES"<<endl;
		}else{
			vi missing;
			FOR1(i,N){
				if(occ[i]==0){
					missing.pb(i);
				}
			}
			assert(missing.size()==2);
			if((missing[0]+missing[1])!=bad[0]){
				cout<<"NO"<<endl;
				continue;
			}
			cout<<"YES"<<endl;

		}	
		// ∫continue;
		// assert(occ.size()==N);
		// int missing=-1;
		// FOR1(i,N){
		// 	if(occ[i]==0){
		// 		missing=i;
		// 	}
		// }
		// assert(missing>=0);




	}


	return 0;
}
