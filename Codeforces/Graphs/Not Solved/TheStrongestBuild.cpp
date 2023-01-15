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



int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin>>N;
	vi slot[N];
	FOR0(i,N){
		int a;
		cin>>a;
		FOR0(j,a){
			int k; cin>>k;
			slot[i].pb(k);
		}
	}
	int M;
	set<vi> bad;
	cin>>M;
	FOR0(i,M){
		vi cur;
		FOR0(j,N){
			int k;
			cin>>k;
			k--;
			cur.pb(k);
		}
		bad.insert(cur);
	}

	priority_queue<pair<int,vi>> cur;
	vi start;
	int startBest=0;
	FOR0(i,N){
		start.pb(slot[i].size()-1);
		startBest+=slot[i][slot[i].size()-1];
	}
	cur.push({startBest,start});
	set<vi> vis;
	while(!cur.empty()){
		vi curV=cur.top().second;
		int curAns=cur.top().first;
		if(bad.find(curV)==bad.end()){
			TRAV(i,cur.top().second){
				cout<<i+1<<" ";
			}
			return 0;
		}
		FOR0(i,N){
			if(curV[i]==0){continue;}
			curAns-=slot[i][curV[i]];
			curV[i]--;
			curAns+=slot[i][curV[i]];
			if(vis.find(curV)==vis.end()){
				vis.insert(curV);
				cur.push({curAns,curV});
			}
			curAns-=slot[i][curV[i]];
			curV[i]++;
			curAns+=slot[i][curV[i]];
		}
		cur.pop();
	}


	return 0;
}
