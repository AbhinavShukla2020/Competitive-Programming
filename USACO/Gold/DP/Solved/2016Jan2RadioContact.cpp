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
 
#define endl "\n"
#define int int64_t 
#define pb push_back
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR0(i,a) FOR(i,0,a)
#define FOR1(i,a) for (int i = (1); i <= (a); ++i)
#define TRAV(a,x) for (auto& a: x)

using pii = pair<int,int>;
using vi = vector<int>;
void fileIO(string filename) {
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
int dist(int x1,int y1,int x2,int y2){
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
int32_t main(){
	fileIO("radio");
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N,M;
	cin>>N>>M;
	int fx,fy,bx,by;
	cin>>fx>>fy>>bx>>by;
	string JohnMoves;
	string BessieMoves;
	cin>>JohnMoves>>BessieMoves;
	pii locJohn[N+1];
	locJohn[0]={fx,fy};
	FOR1(i,N){
		if(JohnMoves.at(i-1)=='N'){
			locJohn[i]={locJohn[i-1].first,locJohn[i-1].second+1};
		}else if(JohnMoves.at(i-1)=='E'){
			locJohn[i]={locJohn[i-1].first+1,locJohn[i-1].second};
		}else if(JohnMoves.at(i-1)=='S'){
			locJohn[i]={locJohn[i-1].first,locJohn[i-1].second-1};
		}else{
			locJohn[i]={locJohn[i-1].first-1,locJohn[i-1].second};
		}
	}
	pii locBess[M+1];
	locBess[0]={bx,by};
	FOR1(i,M){
		if(BessieMoves.at(i-1)=='N'){
			locBess[i]={locBess[i-1].first,locBess[i-1].second+1};
		}else if(BessieMoves.at(i-1)=='E'){
			locBess[i]={locBess[i-1].first+1,locBess[i-1].second};
		}else if(BessieMoves.at(i-1)=='S'){
			locBess[i]={locBess[i-1].first,locBess[i-1].second-1};
		}else{
			locBess[i]={locBess[i-1].first-1,locBess[i-1].second};
		}
	}
	// TRAV(i,locJohn){
	// 	cout<<i.first<<" "<<i.second<<endl;
	// }
	// cout<<endl<<endl;
	// TRAV(j,locBess){
	// 	cout<<j.first<<" "<<j.second<<endl;
	// }
	//cout<<"hi"<<endl;
	//return 0;
	vector<vector<int>> dp(N+1,vector<int>(M+1,9000000000000));
	dp[0][0]=0;
	FOR0(i,N+1){
		FOR0(j,M+1){
			if(i!=0){
				dp[i][j]=min(dp[i][j],dp[i-1][j]+dist(locJohn[i].first,locJohn[i].second,locBess[j].first,locBess[j].second));
			}
			if(j!=0){
				dp[i][j]=min(dp[i][j],dp[i][j-1]+dist(locJohn[i].first,locJohn[i].second,locBess[j].first,locBess[j].second));
			}
			if(i!=0 && j!=0){
				dp[i][j]=min(dp[i][j],dp[i-1][j-1]+dist(locJohn[i].first,locJohn[i].second,locBess[j].first,locBess[j].second));
			}
		}
	}
	// FOR0(i,N+1){
	// 	FOR0(j,M+1){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	cout<<dp[N][M]<<endl;


	return 0;
}
