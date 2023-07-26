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
#define int int64_t 
#define pb push_back
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR0(i,a) FOR(i,0,a)
#define FOR1(i,a) for (int i = (1); i <= (a); ++i)
#define TRAV(a,x) for (auto& a: x)

using pii = pair<int,int>;
using vi = vector<int>;

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--){
		int N,K;
		cin>>N>>K;
		vi in(N);
		FOR0(i,N){
			cin>>in[i];
		}
		if(K==1){
			cout<<"YES"<<endl;
			continue;
		}
		int start=in[0];
		int cnt1=1;
		int ind1=-1;
		FOR1(i,N-1){
			if(cnt1<K && in[i]==start){
				cnt1++;
				if(cnt1==K){
					ind1=i;
				}
			}

		}
		int end=in[N-1];
		int cnt2=1;
		int ind2=-1;
		for(int i=N-2;i>=0;i--){
			if(cnt2<K && in[i]==end){
				cnt2++;
				if(cnt2==K){
					ind2=i;
				}
			}
		}
		if(start==end && ind1!=(-1)){
			cout<<"YES"<<endl;
			continue;
		}
		if(ind1==(-1) || ind2==(-1)){
			cout<<"NO"<<endl;
			continue;
		}
		if(ind2>ind1){
			cout<<"YES"<<endl;
			continue;
		}
		cout<<"NO"<<endl;


	}


	return 0;
}
