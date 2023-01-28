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

void fileIO(string filename) {
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}

int max(int a,int b){
	if(a>b){
		return a;
	}else{
		return b;
	}
}

int N,M,K;
bool f(int x){
	int cur=N;
	int curDay=1;
	while(cur>0){
		if(curDay>(K)){
			return false;
		}
		int y=floor(cur/x);
		if(y<M){
			int days=ceil(cur/M);
			if((curDay+days)>(K)){
				return false;
			}else{
				return true;
			}
		}
		int days=0;
		if(cur%y==0){
			days=max(1,(cur/y)-x+1);
		}else{
			days=max(1,floor(cur/y)-x);
		}
		curDay+=days;
		cur-=days*y;
	}
	return true;
}


int last_true(int lo, int hi) {
	lo--;
	for (int dif = hi - lo; dif > 0; dif /= 2) {
		while (lo + dif <= hi && f(lo + dif)) {
			lo += dif;
		}
	}
	return lo;
}

int32_t main(){
	fileIO("loan");
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>K>>M;

	cout<<last_true(1,1000000000000000);


	return 0;
}
