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

vector<int> nums;
int N,K;

bool f(int a){
	int psum[N+1];
	FOR0(i,N+1){
		psum[i]=0;
	}
	psum[0]=0;
	FOR1(i,N){
		psum[i]=psum[i-1];
		if(nums[i-1]>=a){
		//	cout<<1;
			psum[i]++;
		}else if(nums[i-1]<a){
			psum[i]--;
		//	cout<<0;
		}
	}
	// cout<<endl;
	// FOR1(i,N){
	// 	cout<<psum[i]<<" ";
	// }
	// cout<<endl;

	int psumMin[N+1];
	psumMin[0]=10000000000000;
	FOR1(i,N){
		psumMin[i]=min(psumMin[i-1],psum[i]);
	}
	// FOR1(i,N){
	// 	cout<<psumMin[i]<<" ";
	// }
	// cout<<endl;
	FOR1(i,N){
		int curVal=psum[i];
		if(i<(K)){
			continue;
		}
		if(i==(K)){
			if(curVal>=1){
				return true;
			}
			continue;
		}
		if((curVal-psumMin[i-K])>=1 || curVal>=1){
			return true;
		}
	}
	return false;
}

int last_true(int lo, int hi) {
	// if none of the values in the range work, return lo - 1
	lo--;
	while (lo < hi) {
		// find the middle of the current range (rounding up)
		int mid = lo + (hi - lo + 1) / 2;
		if (f(mid)) {
			// if mid works, then all numbers smaller than mid also work
			lo = mid;
		} else {
			// if mid does not work, greater values would not work either
			hi = mid - 1;
		}
	}
	return lo;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>K;
	FOR0(i,N){
		int a;
		cin>>a;
		nums.pb(a);
	}
	// cout<<f(7)<<endl;
	// return 0;
	cout<<last_true(0,1000000000000)<<endl;
	// FOR1(i,5){
	// 	cout<<"f("<<i<<") : "<<f(i)<<endl;
	// }



	return 0;
}
