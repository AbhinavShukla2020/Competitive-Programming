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
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		int ans=0;
		if(b<=d){
			ans+=abs(b-d);
			a+=abs(b-d);
			b=d;
		}else{
			ans=-1;
			a=c-1;
		}

		if(a>=c){
			ans+=a-c;
		}else{
			ans=-1;
		}
		cout<<ans<<endl;
	}


	return 0;
}
