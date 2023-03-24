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

struct boot{
	int len,agil;
};
bool cmp(vi a,vi b){
	return a[0]>b[0];
}
void fileIO(string filename) {
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
int32_t main(){
	fileIO("snowboots");
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N,B;
	cin>>N>>B;
	vi snow(N);
	FOR0(i,N){
		cin>>snow[i];
	}
	//6:09
	vector<boot> boots;
	FOR0(i,B){
		int a,b;
		cin>>a>>b;
		boots.pb({b,a});
	}
	map<pii,int> vis;
	//bool vis[N];
	// FOR0(i,N){
	// 	vis[i]=false;
	// }
	queue<vector<int>> cur; //skipped, index, pos
	FOR0(i,B){
		for(int j=0;j<=min(N-1,boots[i].len);j++){
			if(snow[j]<=boots[i].agil){
				cur.push({i,i,j});
				//vis[{0,j}]=i;
			}
		}
	}
	// priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> cur2=cur;
	// while(!cur2.empty()){
	// 	cout<<cur2.top()[0]<<" "<<cur2.top()[1]<<" "<<cur2.top()[2]<<endl;
	// 	cur2.pop();
	// }
	// cout<<"in"<<endl;
	int ans=10000000000000000;
	while(!cur.empty()){
		//cout<<"hi"<<endl;
		int curSkipped=cur.front()[0];
		int curInd=cur.front()[1];
		int curPos=cur.front()[2];
		cur.pop();
		if(curPos==(N-1)){
			ans=min(ans,curSkipped);
			//break;
		}
		for(int i=curInd;i<B;i++){
			//cout<<boots[i].len
			for(int k=curPos;k<=min(N-1,boots[i].len+curPos);k++){
				if(vis.find({curPos,k})==vis.end() || (vis.find({curPos,k})!=vis.end() && vis[{curPos,k}]<curInd)){
					if(snow[k]<=boots[i].agil && snow[curPos]<=boots[i].agil){
						cur.push({curSkipped+i-curInd,i,k});
						vis[{curPos,k}]=i;
					//	break;
					}
				}
			}
		}
	}

	cout<<ans<<endl;


	return 0;
}
