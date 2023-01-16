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
		vector<int> in(N);
		FOR0(i,N){
			cin>>in[i];
		}
		sort(in.begin(),in.end());
		int ans=0;
		bool zero=true;
		FOR0(i,N){
			if(in[i]==0){
				zero=false;
			}
		}
		if(zero){
			ans++;
		}
		FOR0(i,N){
			if(i!=(N-1)){
				if(in[i]<=(i) && in[i+1]>(i+1)){
					ans++;
				}
			}else{
				if(in[i]<=(i)){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}


	return 0;
}
