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

const int MAXN=2e5+1;

vector<vector<int>> adj(MAXN);
vector<int> deepest(MAXN);
int ans=0;

int deepestRoot(int a,int b){
	int curAns=0;
	for(int k : adj[a]){
		if(k==b){continue;}
		curAns=max(curAns,deepestRoot(k,a)+1);
	}
	deepest[a]=curAns;
	return curAns;
}

void getAns(int a,int b){
	vector<int> dists;
	for(int i : adj[a]){
		if(i==b){continue;}
		dists.push_back(deepest[i]);
	}
	if(dists.size()==0){
		return;
	}else if(dists.size()==1){
		ans=max(ans,dists[0]+1);
	}else{
		sort(dists.begin(),dists.end(),greater<int>());
		ans=max(ans,dists[0]+dists[1]+2);
	}
	for(int i : adj[a]){
		if(i==b){continue;}
		getAns(i,a);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin>>N;
	for(int i=0;i<N-1;i++){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	deepestRoot(1,-1);
	getAns(1,-1);
	cout<<ans<<endl;
	return 0;
}
