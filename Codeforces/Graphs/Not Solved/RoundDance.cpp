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

bool vis[200001];

bool dfs(int a,int par,const vector<set<int>>& adj){
	//cout<<a+1<<" "<<par+1<<endl;
	vis[a]=true;
	bool notCycle=true;
	TRAV(i,adj[a]){
		//cout<<" "<<i+1<<endl;
		// if(i==par){
		// 	continue;
		// }

		if(!vis[i]){
			notCycle&=dfs(i,a,adj);
		}else if(i!=par){
			notCycle=0;
		}
	}
	return notCycle;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--){
		int N;
		cin>>N;
		vi in(N);
		vi next(N);
		vector<set<int>> adj(N);
		FOR0(i,N){
			cin>>in[i];
			in[i]=in[i]-1;
			//cout<<i<<" "<<in[i]<<endl;
			adj[i].insert(in[i]);
			adj[in[i]].insert(i);
		}
		// FOR0(i,N){
		// 	cout<<i<<" : ";
		// 	TRAV(j,adj[i]){
		// 		cout<<j<<" , ";
		// 	}
		// 	cout<<endl;
		// }
		// cout<<endl<<endl<<endl;
		FOR0(i,N){
			vis[i]=false;
		}
		int closed=0;
		int open=0;
		FOR0(i,N){
			if(!vis[i]){
				//cout<<i+1<<endl;
				if(dfs(i,-1,adj)){
					open++;
				}else{
					closed++;
				}
				//cout<<endl<<endl<<endl;
			}
		}
		if(open==0){
			cout<<closed<<" "<<closed+open<<endl;
		}else{
			cout<<closed+1<<" "<<closed+open<<endl;
		}





	}


	return 0;
}
