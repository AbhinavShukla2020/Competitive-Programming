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
const int MAXN=5000;
int N,M;
int K=0;
vector<vector<int>> adj(MAXN+1);
map<pii,int> vals;

void fileIO(string filename) {
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}


int f(int b,int a){	
	int ans=1;
	for(int k : adj[a]){
		if(vals[{a,k}]>=K && k!=b){
			ans+=f(a,k);
		}
	}
	return ans;
}
int main(){
	fileIO("mootube");
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>M;
	for(int i=0;i<N-1;i++){
		int a,b,c;
		cin>>a>>b>>c;
		adj[a].push_back(b);
		adj[b].push_back(a);
		vals[{a,b}]=c;
		vals[{b,a}]=c;
	}
	for(int i=0;i<M;i++){
		int a,b;
		cin>>a>>b;
		K=a;
		cout<<f(0,b)-1<<endl;
	}




	return 0;
}