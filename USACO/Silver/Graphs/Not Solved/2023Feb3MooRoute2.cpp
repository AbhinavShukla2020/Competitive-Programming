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

int min(int a, int b){
	if(a<b){
		return a;
	}
	return b;
}

void print(priority_queue<pair<pii,int>> a){
	priority_queue<pair<pii,int>> b=a;
	cout<<endl;
	while(!b.empty()){
		cout<<b.top().first.first<<" "<<b.top().first.second<<" "<<b.top().second<<endl;
		b.pop();
	}
	cout<<endl;
	return;
}
int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N,M;
	cin>>N>>M;
	priority_queue<pair<pii,int>> adj[N+1];
	int ans[N+1];
	FOR0(i,M){
		int c,r,d,s;
		cin>>c>>r>>d>>s;
		adj[c].push({{r,s},d});
	}
	// cout<<"hi"<<endl;
	// return 1;
	FOR0(i,N){
		ans[i+1]=1000000000000000;
		int a;
		cin>>a;
		priority_queue<pair<pii,int>> curAdj=adj[i+1];
		while(!adj[i+1].empty()){
			adj[i+1].pop();
		}
		while(!curAdj.empty()){
			pair<pii,int> j=curAdj.top();
			curAdj.pop();
			adj[i+1].push({{j.first.first-a,j.first.second},j.second});
		}

	}
	ans[1]=0;

	queue<pair<int,int>> flights;
	while(!adj[1].empty()){
		pair<pii,int> j=adj[1].top();
		adj[1].pop();
		flights.push({j.second,j.first.second});
	//	cout<<"      "<<j.second<<" "<<j.first.second<<endl;
	}


	while(!flights.empty()){
		pair<int,int> curFlight=flights.front();
		ans[curFlight.first]=min(ans[curFlight.first],curFlight.second);
		flights.pop();

		while(!adj[curFlight.first].empty() && adj[curFlight.first].top().first.first>=curFlight.second){
		//	cout<<"hi"<<endl;
			flights.push({adj[curFlight.first].top().second,adj[curFlight.first].top().first.second});
			ans[adj[curFlight.first].top().second]=min(adj[curFlight.first].top().first.second,ans[adj[curFlight.first].top().second]);
			adj[curFlight.first].pop();
		}
	}
	FOR1(i,N){
		if(ans[i]==1000000000000000){
			cout<<-1<<endl;
			continue;
		}
		cout<<ans[i]<<endl;
	}


	return 0;
}
