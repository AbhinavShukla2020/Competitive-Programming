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

int xDiff=0,yDiff=0;
string in;
int x,y;
int x2,y2;
bool f(int curTime){
	int rounds=curTime/(in.size());
	int curX=x+rounds*xDiff;
	int curY=y+rounds*yDiff;
	FOR0(j,curTime%in.size()){
		char i=in.at(j);
		if(i=='U'){
			curY++;
		}else if(i=='D'){
			curY--;
		}else if(i=='R'){
			curX++;
		}else{
			curX--;
		}
	}
	if((abs(x2-curX)+abs(y2-curY))>curTime){
		return false;
	}
	return true;
}

int first_true(int lo, int hi) {
	int orighi=hi+1;
	hi++;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (f(mid)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	if(orighi==lo){
		return -1;
	}
	return lo;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>x>>y;
	
	cin>>x2>>y2;
	int N;
	cin>>N;
	cin>>in;
	TRAV(i,in){
		if(i=='U'){
			yDiff++;
		}else if(i=='D'){
			yDiff--;
		}else if(i=='R'){
			xDiff++;
		}else{
			xDiff--;
		}
	}
	cout<<first_true(0,100000000000000000)<<endl;

	return 0;
}
