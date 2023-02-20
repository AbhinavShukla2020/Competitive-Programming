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

bool grid[1001][1001]; //true R, false L

void fileIO(string filename) {
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}

int32_t main(){
	//fileIO("leftout");
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin>>N;

	FOR0(i,N){
		string s;
		cin>>s;
		FOR0(j,N){
			grid[i][j]=(s.at(j)=='R');
		}
	}

	FOR0(c,N){
		if(grid[0][c]==false){
			FOR0(r,N){
				grid[r][c]=!grid[r][c];
			}
		}
	}


	// FOR0(r,N){
	// 	FOR0(c,N){
	// 		cout<<grid[r][c];
	// 	}
	// 	cout<<endl;
	// }
	// cout<<endl<<endl;

	FOR1(r,N-1){
		if(grid[r][0]==false){
			// cout<<r<<endl;
			FOR0(c,N){
				grid[r][c]=!grid[r][c];
			}
		}
	}

	bool allR=true;
	bool allL=true;
	int LCnt=0;

	FOR0(r,N){
		FOR0(c,N){
			if(grid[r][c]){
				allL=false;
			}else{
				LCnt++;
				allR=false;
			}
		}
	}
	//cout<<LCnt<<endl;
	if(allR){
		//cout<<"eyoe"<<endl;
		cout<<-1<<endl;
		return 0;
	}
	if(LCnt==(N*N-2*N+1)){
		cout<<"1 1"<<endl;
		return 0;
	}
	//cout<<"yo"<<endl;
	// FOR0(r,N){
	// 	FOR0(c,N){
	// 		cout<<grid[r][c];
	// 	}
	// 	cout<<endl;
	// }

	if(LCnt==1){
		FOR0(r,N){
			FOR1(c,N-1){
				if(!grid[r][c]){
					cout<<r+1<<" "<<c+1<<endl;
				}
			}
		}
	}else if(LCnt==N-1){
		FOR0(r,N){
			bool all=true;
			FOR1(c,N-1){
				if(grid[r][c]){
					all=false;
					break;
				}
			}
			if(all){
				cout<<r+1<<" "<<1<<endl;
				return 0;
			}
		}

		FOR0(c,N){
			bool all=true;
			FOR0(r,N){
				if(grid[r][c]){
					all=false;
					break;
				}
			}
			if(all){
				cout<<"1 "<<c+1<<endl;
				return 0;
			}
		}
		//cout<<"eyoe2"<<endl;
		cout<<-1<<endl;
	}else{
		//cout<<"eyoe3"<<endl;
		cout<<-1<<endl;
	}






	return 0;
}
