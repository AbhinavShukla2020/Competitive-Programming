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
		int n,x,p;
		cin>>n>>x>>p;
		int cur=0;
		bool works=false;
		if(n%1==2){
			for(int i=1;i<=min(4*n+5,p);i++){
				cur+=i;
				if(((cur+x) % n) == 0){
					works=true;
					break;
				}
			}
		}else{
			for(int i=1;i<=min(4*n+5,p);i++){
				cur+=i;
				if(((cur+x) % (n)) == 0){
					works=true;
					break;
				}
			}
		}
		if(works){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}


	return 0;
}
