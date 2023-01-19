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

void fileIO(string filename) {
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}

int32_t main(){
	fileIO("cereal");
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N,M;
	cin>>N>>M;
	int state[N+1];
	int f[N+1];
	int s[N+1];
	FOR1(i,N){
		state[i]=3;
		cin>>f[i];
		cin>>s[i];
	}
	int occ[M+1];
	FOR1(i,M){
		occ[i]=0;
	}
	int ans=0;
	vector<int> finalAns;
	for(int i=N;i>=1;i--){
		int curC=i;
		int pos=f[curC];
		ans++;
		while(1){
			if(occ[pos]==0){
				occ[pos]=curC;
				if(pos==f[curC]){
					state[curC]=1;
				}else if(pos==s[curC]){
					state[curC]=2;
				}
				break;
			}else if(occ[pos]<curC){
				ans--;
				break;
			}else{
				if(pos==f[curC]){
					state[curC]=1;
				}else{
					state[curC]=2;
				}
				int newC=occ[pos];
				occ[pos]=curC;
				if(state[newC]==2){
					state[newC]=3;
					ans--;
					break;
				}
				state[newC]=3;
				curC=newC;
				pos=s[curC];
			}
		}
		finalAns.pb(ans);
	}
	reverse(finalAns.begin(),finalAns.end());
	TRAV(i,finalAns){
		cout<<i<<endl;
	}


	return 0;
}
