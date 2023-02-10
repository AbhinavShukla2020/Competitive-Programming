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

const int MAXN=1500+2;
int N;
bool dir[MAXN][MAXN];
int num_children[MAXN][MAXN];
map<pii,int> vat;
bool vis[MAXN][MAXN];
int ans=0;
int startAns[MAXN][MAXN];
bool vis2[MAXN][MAXN];
void getChildren(int r1,int c1){
	queue<pii> cur;
	cur.push({r1,c1});
	while(!cur.empty()){
		int r=cur.front().first;
		int c=cur.front().second;
		if(r-1>=0 && !dir[r-1][c]){
			num_children[r][c]+=num_children[r-1][c];
		}
		if(c-1>=0 && dir[r][c-1]){
			num_children[r][c]+=num_children[r][c-1];
		}
		if((c+1)<N && !vis[r][c+1]){
			cur.push({r,c+1});
			vis[r][c+1]=true;
		}
		if((r+1)<N && !vis[r+1][c]){
			cur.push({r+1,c});
			vis[r+1][c]=true;
		}
		cur.pop();
	}

}

int getStartAns(int r,int c){
	vis2[r][c]=true;
	if(dir[r][c]==1){
		if((c+1)>=N){
			startAns[r][c]=vat[{r,c+1}];
			return vat[{r,c+1}];
		}
		if(vis2[r][c+1]==true){
			startAns[r][c]=startAns[r][c+1];
			return startAns[r][c+1];
		}
		startAns[r][c]=getStartAns(r,c+1);
		return startAns[r][c];
	}else{
		if((r+1)>=N){
			startAns[r][c]=vat[{r+1,c}];
			return vat[{r+1,c}];
		}
		if(vis2[r+1][c]==true){
			startAns[r][c]=startAns[r+1][c];
			return startAns[r+1][c];
		}
		startAns[r][c]=getStartAns(r+1,c);
		return startAns[r][c];
	}
}

void update(){
	int r,c;
	cin>>r>>c;
	r--;
	c--;
	int curR=r, curC=c;
	int oldCnt=0;
	int oldVat;
	while(curR<N && curC<N){
		if(!(curR==r && curC==c)){
			num_children[curR][curC]-=num_children[r][c];
		}
		if(dir[curR][curC]){
			curC++;
			oldCnt++;
		}else{
			curR++;
			oldCnt++;
		}
	}
	oldVat=vat[{curR,curC}];
	if(dir[r][c]){
		dir[r][c]=false;
	}else{
		dir[r][c]=true;
	}
	int newCnt=0;
	curR=r;
	curC=c;
	while(curR<N && curC<N){
		if(!(curR==r && curC==c)){
			num_children[curR][curC]+=num_children[r][c];
		}
		if(dir[curR][curC]){
			curC++;
			newCnt++;
		}else{
			curR++;
			newCnt++;
		}
	}
	int newVat=vat[{curR,curC}];
	ans-=(num_children[r][c])*oldVat;
	ans+=(num_children[r][c])*newVat;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>N;
	FOR0(r,N+1){
		FOR0(c,N+1){
			vis[r][c]=false;
			vis2[r][c]=false;
			num_children[r][c]=1;
			startAns[r][c]=0;
		}
	}
	FOR0(i,N){
		string in;
		cin>>in;
		int counter=0;
		TRAV(j,in){
			if(j=='R'){
				dir[i][counter]=1;
			}else{
				dir[i][counter]=0;
			}
			counter++;
		}
		int val;
		cin>>val;
		vat[{i,N}]=val;
	}
	FOR0(i,N){
		int a;
		cin>>a;
		vat[{N,i}]=a;
	}
	getChildren(0,0);
	FOR0(r,N){
		FOR0(c,N){
			if(!vis2[r][c]){
				getStartAns(r,c);
			}
		}
	}
	FOR0(r,N){
		FOR0(c,N){
			ans+=startAns[r][c];
		}
	}
	cout<<ans<<endl;
	int Q;
	cin>>Q;
	FOR0(i,Q){
		update();
		cout<<ans<<endl;
	}



	return 0;
}
