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

const int dx[4]={-1,0,0,1};
const int dy[4]={0,1,-1,0};

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--){
		int N,M;
		cin>>N>>M;
		int grid[N][M];
		bool vis[N][M];
		int shouldG=0;

		FOR0(r,N){
			string in;
			cin>>in;
			FOR0(c,M){
				vis[r][c]=false;
				grid[r][c]=in.at(c);
				if(in.at(c)=='G'){
					shouldG++;
				}
			}
		}
		//return 0;
		if(grid[N-1][M-1]=='B'){
			cout<<"NO"<<endl;
			continue;
		}
		queue<pii> bfs;
		bfs.push({N-1,M-1});
		vis[N-1][M-1]=true;
		while(!bfs.empty()){
			int curR=bfs.front().first;
			int curC=bfs.front().second;
			bfs.pop();
			assert(grid[curR][curC]!='B');
			bool done=false;
			FOR0(k,4){
					int i=dx[k];
					int j=dy[k];
					if(!(0<=i+curR && i+curR<=N-1 && 0<=j+curC && j+curC<=M-1)){
						continue;
					}
					int newR=curR+i;
					int newC=curC+j;
					if(grid[newR][newC]=='B'){
						grid[curR][curC]='#';
						done=true;
					}
				
			}
			if(done){
				continue;
			}
			FOR0(k,4){
					int i=dx[k];
					int j=dy[k];
					if(!(0<=i+curR && i+curR<=N-1 && 0<=j+curC && j+curC<=M-1)){
						continue;
					}
					int newR=curR+i;
					int newC=curC+j;
					if(grid[newR][newC]!='#' && !vis[newR][newC]){
						bfs.push({newR,newC});
						vis[newR][newC]=true;
					}
			}
			
		}
		FOR0(r,N){
			FOR0(c,M){
				vis[r][c]=false;
			}
		}
		
		if(grid[N-1][M-1]!='#'){
			bfs.push({N-1,M-1});
		}
		vis[N-1][M-1]=true;
		bool ans=true;
		int gCnt=0;
		while(!bfs.empty()){
			int curR=bfs.front().first;
			int curC=bfs.front().second;
			bfs.pop();
			if(grid[curR][curC]=='B'){
				ans=false;
				break;
			}
			if(grid[curR][curC]=='G'){
				gCnt++;
			}
			FOR0(k,4){
					int i=dx[k];
					int j=dy[k];
					int newR=curR+i;
					int newC=curC+j;
					if(!(0<=i+curR && i+curR<=N-1 && 0<=j+curC && j+curC<=M-1)){
						continue;
					}
					if(grid[newR][newC]!='#' && !vis[newR][newC]){
						bfs.push({newR,newC});
						vis[newR][newC]=true;
					}
			}

		}
		if(gCnt==shouldG && ans){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}

	}
	return 0;
}
