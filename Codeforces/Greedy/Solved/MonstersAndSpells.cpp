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

int max(int a,int b){
	if(a>b){
		return a;
	}
	return b;
}
bool cmp(pii a, pii b){
	return a.first-a.second<b.first-b.second;
}
int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	FOR0(i,T){
		int N;
		cin>>N;
		vector<pii> monsters(N);
		FOR0(i,N){
			cin>>monsters[i].first;
		}
		FOR0(i,N){
			cin>>monsters[i].second;
		}
		sort(monsters.begin(),monsters.end(),cmp);
		int l=0,r=0;
		int ans=0;
		bool checkLast=false;
		FOR0(i,N){
			int curR=monsters[i].first;
			int curL=monsters[i].first-monsters[i].second+1;
			if(curL>r){
				if(!(r==0 && l==0)){
					ans+=((r-l+1)*(r-l+2))/2;
				}
				l=curL;
				r=curR;
				checkLast=true;
			}else{
				checkLast=false;
				r=max(curR,r);
			}
		}
		checkLast=false;
		if(!checkLast){
			ans+=((r-l+1)*(r-l+2))/2;
		}
		cout<<ans<<endl;
	}


	return 0;
}
