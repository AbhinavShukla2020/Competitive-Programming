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
#define int long long int
#define pb push_back
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR0(i,a) FOR(i,0,a)
#define FOR1(i,a) for (int i = (1); i <= (a); ++i)
#define TRAV(a,x) for (auto& a: x)

using pii = pair<int,int>;
using vi = vector<int>;

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N,K;
	cin>>N>>K;
	vi in(N);
	vector<pii> in2;
	FOR0(i,N){
		cin>>in[i];
		int twoCnt=0;
		int fiveCnt=0;
		int a=in[i];
		while((a % 2)==0){
			twoCnt++;
			a/=2;
		}
		int b=in[i];
		while((b%5)==0){
			fiveCnt++;
			b/=5;
		}
		in2.pb({twoCnt,fiveCnt});
	}
	int cur[5300][K+10];
	FOR0(i,5299){
		FOR0(j,K+10){
			cur[i][j]=-1;
		}
	}
	cur[0][0]=0;
	FOR1(i,N){
		int cur2=in2[i-1].first;
		int cur5=in2[i-1].second;
		for(int k=K;k>=0;k--){
			for(int j=5200;j>=0;j--){
				if(cur[j][k]<0){continue;}
				cur[j+cur5][k+1]=max(cur[j+cur5][k+1],cur[j][k]+cur2);
			}
		}

	}
	
	
	int ans=0;
	FOR0(i,5200){
		ans=max(ans,min(i,cur[i][K]));
	}	
	cout<<ans<<endl;

	return 0;
}
