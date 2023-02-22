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

const int MAXN=2e5+1;
bool works=true;
bool vis1[MAXN];
int cnt1=0;
int cnt3=0;
set<pair<int,bool>> adj[MAXN];
bool color1[MAXN];
void dfs1(int a,bool state){
	cnt3++;
	vis1[a]=true;
	if(state){cnt1++;}
	TRAV(i,adj[a]){
		if(vis1[i.first]){
			if(i.second && color1[i.first]!=color1[a]){
				works=false;
				return;
			}
			if(!i.second && color1[i.first]==color1[a]){
				works=false;
				return;
			}
		}else{
			if(i.second){
				color1[i.first]=state;
				dfs1(i.first,state);
			}else{
				color1[i.first]=!state;
				dfs1(i.first,!state);
			}

		}
	}
}



int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--){
		int N,M;
		cin>>N>>M;
		FOR1(i,N){
			adj[i].clear();
		}
		FOR0(i,M){
			int a,b;
			string c;
			cin>>a>>b>>c;
			if(c.at(0)=='i'){
				adj[a].insert({b,0});
				adj[b].insert({a,0});
			}else{
				adj[a].insert({b,1});
				adj[b].insert({a,1});
			}
		}

		FOR1(i,N){
			vis1[i]=false;
			color1[i]=-1;
		}
		int ans=0;
		works=true;
		FOR1(i,N){
			if(!vis1[i]){
				cnt1=0;
				cnt3=0;
				color1[i]=0;
				dfs1(i,0);
				ans+=max(cnt1,cnt3-cnt1);
			}
		}
		if(!works){
			cout<<-1<<endl;
			continue;
		}
		cout<<ans<<endl;
	}


	return 0;
}
