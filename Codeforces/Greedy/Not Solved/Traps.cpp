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
		int N,M;
		cin>>N>>M;
		vector<int> in(N);
		int ans=0;
		FOR0(i,N){
			int a;
			cin>>a;
			ans+=a;
			in[i]=a-(N-1-i);
		}
		sort(in.begin(),in.end(),greater<int>());
		FOR0(i,min(M,N)){
			ans-=in[i];
		}
		ans-=M*(M-1)/2;
		cout<<ans<<endl;
	}


	return 0;
}
