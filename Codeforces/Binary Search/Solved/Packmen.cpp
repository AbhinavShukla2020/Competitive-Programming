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

int pmen=0;
int ast=0;
vector<int> pmenPos;
vi astPos;
int max(int a,int b){
	if(a>b){
		return a;
	}
	return b;
}
bool f(int timeMax){
	int ind=0;
	int r=-1;
	FOR0(i,pmen){
		if(ind==ast){
			return true;
		}
		int timeTaken=0;
		int origInd=ind;
		if(astPos[ind]<pmenPos[i]){
			if((pmenPos[i]-astPos[ind])>timeMax){
				return false;
			}
			timeTaken+=2*(pmenPos[i]-astPos[ind]);
		}
		auto low=lower_bound(astPos.begin(),astPos.end(),pmenPos[i]);
		if(low==astPos.end()){
			return true;
		}
		ind=low-astPos.begin();
		int case1ind=ind;
		int curPos=pmenPos[i];
		auto it=upper_bound(astPos.begin(),astPos.end(),timeMax-timeTaken+curPos);
		if(it==astPos.end()){
			return true;
		}
		case1ind=max(ind,it-astPos.begin());
		int case2ind=ind;
		if((max(0,pmenPos[i]-astPos[origInd])+2*(astPos[ind]-pmenPos[i]))<=timeMax){
			auto it2=upper_bound(astPos.begin(),astPos.end(),(timeMax-max(0,pmenPos[i]-astPos[origInd]))/2+curPos);
			if(it2==astPos.end()){
				return true;
			}
			case2ind=it2-astPos.begin();
		}
		ind=max(case1ind,case2ind);
	}
	if(ind==ast){
		return true;
	}
	return false;
}

int first_true(int lo, int hi) {
	hi++;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (f(mid)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}
int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin>>N;
	string in;
	cin>>in;
	FOR0(i,N){
		if(in.at(i)=='*'){
			astPos.pb(i);
			ast++;
		}else if(in.at(i)=='P'){
			pmenPos.pb(i);
			pmen++;
		}
	}
	cout<<first_true(1,1000000);

	return 0;
}
