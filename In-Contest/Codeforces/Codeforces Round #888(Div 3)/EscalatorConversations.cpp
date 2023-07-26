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
		int N,M,K,H;
		cin>>N>>M>>K>>H;
		int ans=0;
		FOR0(i,N){
			int a;
			cin>>a;
			if((a-H)%K==0 && abs(a-H)<=(M-1)*K && a!=H){
		//		cout<<a<<" ";
				ans++;
			}
		}
	//	cout<<endl;
		cout<<ans<<endl;
	}


	return 0;
}
