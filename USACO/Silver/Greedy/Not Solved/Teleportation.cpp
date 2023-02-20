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

void fileIO(string filename) {
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}

int32_t main(){
	fileIO("teleport");
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<int,int> slope;
	int N;
	cin>>N;
	int ans=0;
	
	FOR0(i,N){
		int s,e;
		cin>>s>>e;
		ans+=abs(s-e);
		if(s<=0 && e>=0){
			slope[0]--;
			slope[e]+=2;
			slope[2*e]--;
		}else if(s>=0 && e<=0){
			slope[0]--;
			slope[e]+=2;
			slope[2*e]--;
		}else if(s>=0 && e>=0 && s<=e){
			if((e-s)<=s){
				continue;
			}
			slope[2*s]--;
			slope[e]+=2;
			slope[2*e-2*s]--;
		}else if(s<=0 && e<=0 && s>=e){
			if((s-e)<=(-s)){
				continue;
			}
			slope[2*s]--;
			slope[e]+=2;
			slope[2*e-2*s]--;
		}
	}
	int best=ans;
	int curSlope=0;
	int curY=ans;
	int past=0;
	TRAV(i,slope){
		curY+=curSlope*(i.first-past);
		best=min(curY,best);
		curSlope+=i.second;
		past=i.first;
	}
	cout<<best<<endl;
	return 0;
}
