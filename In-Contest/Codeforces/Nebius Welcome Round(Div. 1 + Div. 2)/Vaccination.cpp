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
		int N,K,D,W;
		cin>>N>>K>>D>>W;
		int ans=0;
		int i=0;
		int a;
		bool done=false;
		while(i<N){
			ans++;
			if(!done){
			//	int a;
				cin>>a;
			}
			done=false;
			i++;
			int used=1;
			int startTime=a+W;
			//cout<<i-1<<" "<<a+W<<endl;
			while(i<N && used<K){
				int curTime;
				cin>>curTime;
				if(curTime<startTime || (curTime>=startTime && curTime-startTime<=D)){
					i++;
					used++;
				}else{
					//cout<<"break: "<<i<<" "<<curTime<<endl;
					a=curTime;
					done=true;
					break;
				}
			}
		}
		cout<<ans<<endl;
		//return 0;
	}


	return 0;
}
