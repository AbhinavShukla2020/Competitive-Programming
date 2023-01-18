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

	bool vis[M+1];
	int state[N+1];
	int f[N+1];
	int s[N+1];
	map<int,int> assign;
	FOR0(i,M+1){
		vis[i]=false;
	}

	int ans=0;
	FOR1(i,N){
		int curF,curS;
		cin>>curF>>curS;
		f[i]=curF;
		s[i]=curS;
		if(!vis[curF]){
			state[i]=1;
			vis[curF]=true;
			assign[curF]=i;
			ans++;
		}else if(!vis[curS]){
			state[i]=2;
			vis[curS]=true;
			assign[curS]=i;
			ans++;
		}else{
			state[i]=3;
		}
	}

	queue<int> want[M+1];
	FOR1(i,N){
		if(state[i]==2 && assign[f[i]]!=i){
			want[f[i]].push(i);
		}
		if(state[i]==3){
			want[f[i]].push(i);
			want[s[i]].push(i);
		}
	}
	
	cout<<ans<<endl;
	FOR1(i,N-1){
		if(state[i]==3){
			cout<<ans<<endl;
			continue;
		}
		int curFree=-1;
		if(state[i]==1){
			curFree=f[i];
		}
		if(state[i]==2){
			curFree=s[i];
		}
		ans--;
		while(1){
			if(curFree==-1){break;}
			if(want[curFree].empty()){break;}
			int newC=want[curFree].front();
			want[curFree].pop();
			if(newC<i || state[newC]==1){
				continue;
			}
			if(state[newC]==3){
				ans++;
				if(curFree==f[newC]){
					state[newC]=1;
				}else if(curFree==s[newC]){
					state[newC]=2;
				}
				break;
			}
			if(state[newC]==2){
				state[newC]=1;
				curFree=s[newC];
				continue;
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}
