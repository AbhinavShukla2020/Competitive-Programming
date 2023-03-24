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
	int N,K;
	cin>>N>>K;
	vector<int> psum(N+2,0);
	FOR0(i,K){
		int a,b;
		cin>>a>>b;
		psum[a]++;
		psum[b+1]--;
	}
	vector<int> cur;
	for(int i=1;i<=N;i++){
		psum[i]+=psum[i-1];
		cur.pb(psum[i]);
	}
	sort(cur.begin(),cur.end());
	cout<<cur[(N+1)/2-1]<<endl;



	return 0;
}
