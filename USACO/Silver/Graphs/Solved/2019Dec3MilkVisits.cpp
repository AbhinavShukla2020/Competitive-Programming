#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>
#include <math.h>

using namespace std;

using ll = long long;
using pii = pair<ll,ll>;

const int MAXN=1e5+1;


int N,M;
vector<vector<int>> adj(MAXN);
string in;
vector<int> group(MAXN,-1);
int curGroup=0;

void fileIO(string filename) {
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}


void dfs(int a, int b){
	group[a]=curGroup;
	for(int i : adj[a]){
		if(i!=b && in.at(a)==in.at(i)){
			dfs(i,a);
		}
	}
}


int main(){
	fileIO("milkvisits");
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin>>N>>M;
	cin>>in;
	in.insert(0,"Z");

	for(int i=0;i<N-1;i++){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	
	for(int i=1;i<=N;i++){
		if(group[i]==-1){
			dfs(i,-1);
			curGroup++;
		}
	}
	

	for(int i=0;i<M;i++){
		int a,b;
		char c;
		cin>>a>>b>>c;
		if(group[a]==group[b]){
			if(in.at(a)==c){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}else{
			cout<<"1";
		}
	}

	return 0;
}