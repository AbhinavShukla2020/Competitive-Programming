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
		int N;
		cin>>N;
		vector<int> in(N);
		FOR0(i,N){
			cin>>in[i];
		}
		sort(in.begin(),in.end());
		int low=1;
		int hi=1;
		bool works=true;
		FOR0(i,N){
			if(!(in[i]>=low && in[i]<=hi)){
				works=false;
			}else{
				if(i!=0){
					hi+=in[i];
				}
			}
		}
		if(works){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}


	return 0;
}
