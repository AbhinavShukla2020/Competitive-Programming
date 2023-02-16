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
#include <cassert>

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
		string in;
		cin>>in;
		int l=0,r=0;
		TRAV(i,in){
			if(i=='('){
				r++;
			}else if(i==')'){
				l++;
			}
		}
		int N=in.size();
		int left=N-l-r;
		int rNeed=0;
		int lNeed=0;
		if(l>r){
			lNeed=(left-(l-r))/2;
			rNeed=left-(lNeed);
		}else{
			rNeed=(left-(r-l))/2;
			lNeed=left-(rNeed);
		}
		int ind=0;
		int lastIndR=0;
		int firstIndL=-1;
		while(rNeed>0){
			if(in[ind]=='?'){
				in[ind]='(';
				rNeed--;
				lastIndR=ind;
			}
			ind++;
		}
		while(lNeed>0){
			if(in[ind]=='?'){
				in[ind]=')';
				lNeed--;
				if(firstIndL==-1){
					firstIndL=ind;
				}
			}
			ind++;
		}
		in[lastIndR]=')';
		in[firstIndL]='(';
		int lcnt=0;
		int rcnt=0;
		bool ans=false;
		TRAV(i,in){
			assert(i!='?');
			if(i=='('){
				rcnt++;
			}else{
				lcnt++;
			}
			if(lcnt>rcnt){
				ans=true;
				break;
			}
		}
		if(ans){
			cout<<"YES"<<endl;
		}else{
			if(lcnt==rcnt){
				cout<<"NO"<<endl;
			}else{
				cout<<"YES"<<endl;
			}
		}
	}

	return 0;
}
