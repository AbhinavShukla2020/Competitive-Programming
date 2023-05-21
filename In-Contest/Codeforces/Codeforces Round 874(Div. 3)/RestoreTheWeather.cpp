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
 


#define endl "\n"
#define int long long int
#define pb push_back
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR0(i,a) FOR(i,0,a)
#define FOR1(i,a) for (int i = (1); i <= (a); ++i)
#define TRAV(a,x) for (auto& a: x)

using pii = pair<int,int>;
using vi = vector<int>;

int32_t main(){
	int T;
	cin>>T;
	while(T--){
		int N,K;
		cin>>N>>K;
		vector<int> in(N);
		vector<int> sorted;
		map<int,vi> vals;
		FOR0(i,N){
			cin>>in[i];
			vals[in[i]].pb(i);
		}
		vector<int> in2(N);
		FOR0(i,N){
			cin>>in2[i];
		}
		sort(in2.begin(),in2.end());
		vector<int> ans(N,-100000000000000);
		int pointer=0;
		TRAV(i,vals){
			TRAV(j,i.second){
				ans[j]=in2[pointer];
				pointer++;
			}
		}
		TRAV(i,ans){
			cout<<i<<" ";
		}
		cout<<endl;
		



	}







}
