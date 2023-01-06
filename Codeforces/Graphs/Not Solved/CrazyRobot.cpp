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

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--){
		int N,M;
		cin>>N>>M;
		char grid[N][M];
		int lr,lc;
		FOR0(i,N){
			FOR0(j,M){
				cin>>grid[i][j];
				if(grid[i][j]=='L'){
					lr=i;
					lc=j;
				}
			}
		}

		int badAdj[N][M];
		bool good[N][M];
		FOR0(r,N){
			FOR0(c,M){
				badAdj[r][c]=0;
				good[r][c]=false;
			}
		}
		FOR0(r,N){
			FOR0(c,M){
				FOR0(i,4){
					if(0<=(r+dx[i]) && (r+dx[i])<N && 0<=(c+dy[i]) && (c+dy[i])<M){
						if(grid[r+dx[i]][c+dy[i]]!='#'){
							badAdj[r][c]++;
						}
					}
				}
			}
		}
		queue<pii> cur;
		cur.push({lr,lc});
		good[lr][lc]=true;
		while(!cur.empty()){
			int r=cur.front().first;
			int c=cur.front().second;
			cur.pop();
			FOR0(i,4){
				if(!((0<=(r+dx[i]) && (r+dx[i])<N && 0<=(c+dy[i]) && (c+dy[i])<M))){continue;}
				if(grid[r+dx[i]][c+dy[i]]=='#'){continue;}
				if(good[r+dx[i]][c+dy[i]]){continue;}
				badAdj[r+dx[i]][c+dy[i]]--;
				if(badAdj[r+dx[i]][c+dy[i]]<=1){
					good[r+dx[i]][c+dy[i]]=true;
					cur.push({r+dx[i],c+dy[i]});
				}
			}
		}
		FOR0(r,N){
			FOR0(c,M){
				if(grid[r][c]=='.' && good[r][c]){
					cout<<'+';
				}else{
					cout<<grid[r][c];
				}
			}
			cout<<'\n';
		}
	}

	


	return 0;
}
