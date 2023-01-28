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
		string k;
		cin>>k;
		//cout<<k<<endl;
		//return 1;
		int cnt=0;
		int ans=0;
		string pi="314159265358979323846264338327950288419716939937510582097494459230781640628620899862";
		TRAV(i,k){
			if(i==pi.at(cnt)){
				ans++;
				cnt++;
			}else{
				break;
			}
		}
		cout<<ans<<endl;

	}


	return 0;
}
