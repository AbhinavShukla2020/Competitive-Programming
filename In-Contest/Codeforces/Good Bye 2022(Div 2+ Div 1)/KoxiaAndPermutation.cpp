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



int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll T;
	cin>>T;
	for(int i=0;i<T;i++){
		ll N,M;
		cin>>N>>M;
		vector<ll> ans(N,-1);
		ll cur=N;
		for(int j=0;j<N;j++){
			ll counter=1;
			while(counter<M && j<N){
				ans[j]=cur;
				j++;
				cur--;
				counter++;
			}
		}
		cur=1;
		for(int j=0;j<N;j++){
			if(ans[j]==-1){
				ans[j]=cur;
				cur++;
			}
		}
		for(ll i : ans){
			cout<<i<<" ";
		}
		cout<<endl;
	}


	return 0;
}
