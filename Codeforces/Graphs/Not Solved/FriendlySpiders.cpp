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

	set<int> primes;
	int spf[300000+10];
	FOR0(i,300000+1){
		spf[i]=-1;
	}
	spf[1]=1;
	
	FOR(i,2,300000+1){
		if(spf[i]==-1){
			primes.insert(i);
			for(int j=i;j<=3e5;j+=i){
				if(spf[j]==-1){
					spf[j]=i;
				}
			}
		}
	}
	int N;
	cin>>N;
	vector<int> in(N);
	vector<vi> adj(300000);
	set<int> nodes;
	map<int,int> index;
	FOR0(i,N){
		int a;
		cin>>a;
		nodes.insert(a);
		index[a]=i;
		in[i]=a;
		int cur=a;
		while(true){
			if(spf[cur]==1 || cur==1){break;}
			adj[a].pb(spf[cur]);
			adj[spf[cur]].pb(a);
			cur/=spf[cur];
		}		
	}

	int prv[300001];
	int s,e;
	cin>>s>>e;
	int s2=s;
	int e2=e;
	if(s==e){
		cout<<1<<endl<<s<<endl;
		return 0;
	}
	
	s=in[s-1];
	e=in[e-1];
	queue<int> cur;
	cur.push(s);
	int dist[300001];
	FOR0(i,300001){
		prv[i]=-1;
		dist[i]=0;
	}

	while(!cur.empty()){
		int v=cur.front();
		TRAV(k,adj[v]){
			if(prv[k]==-1){
				cur.push(k);
				prv[k]=v;
			}
		}
		cur.pop();
	}
	if(prv[e]==-1){
		cout<<-1<<endl;
		return 0;
	}
	
	vi ans;
	int cur2=e;
	while(cur2!=s){
		cur2=prv[cur2];
		if((cur2!=s) && nodes.find(cur2)!=nodes.end() && primes.find(cur2)==primes.end())
			ans.pb(index[cur2]+1);
	}

	ans.pb(s2);
	reverse(ans.begin(),ans.end());
	ans.pb(e2);
	cout<<ans.size()<<endl;
	TRAV(i,ans){
		cout<<i<<" ";
	}


	return 0;
}
