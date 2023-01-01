#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>

using namespace std;

using ll = long long;
using pii = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;

#define pb push_back
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR0(i,a) FOR(i,0,a)
#define FOR1(i,a) for (int i = (1); i <= (a); ++i)
#define TRAV(a,x) for (auto& a: x)

int min(int a,int b){
	if(a<b){
		return a;
	}
	return b;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll T;
	cin>>T;
	FOR0(t,T){
		ll N,M;
		cin>>N>>M;
		vl first(N);
		vl second(M);
		FOR0(i,N){
			cin>>first[i];
		}
		FOR0(i,M){
			ll a;
			cin>>a;
			ll curBest=0;
			for(int i=0;i<N;i++){
				if((a-first[i]>(a-first[curBest]))){
					curBest=i;
				}
			}
			first[curBest]=a;
		}
		
		ll ans=0;
		for(ll i : first){
			ans+=i;
		}
		cout<<ans<<endl;

	}


	return 0;
}
