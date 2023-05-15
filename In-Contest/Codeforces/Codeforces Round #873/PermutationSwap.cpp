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

int gcd(int a, int b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--){
		int N;
		cin>>N;
		vector<int> in(N);
		vector<int> ind(N+1);
		FOR0(i,N){
			cin>>in[i];
			ind[in[i]]=i;
		}
		int ans=-1;
		
		FOR1(i,N){
			if((ind[i]+1)==i){

			}else{
			//	cout<<i<<" "<<ind[i]<<" "<<abs(ind[i]-i+1)<<endl;
				if(ans==-1){
					ans=abs(ind[i]-i+1);
				}else{
					ans=gcd(ans,abs(ind[i]-i+1));
				}
			}
		}
		cout<<ans<<endl;



	}


	return 0;
}
