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
const int MOD=1e9+7;
const int off=5e3;
int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N,X;
	cin>>N>>X;
	vi in(N+1);
	FOR1(i,N){
		cin>>in[i];
	}
	sort(in.begin(),in.end());
	int dp1[N+2][X+off+1];
	int dp2[N+2][X+off+1];
	
	FOR0(i,N+2){
		FOR0(j,2*X+2){
			dp1[i][j]=0;
			dp2[i][j]=0;
		}
	}
	dp2[0][off]=1;

	FOR1(k,N){
		FOR0(i,N+1){
			for(int j=0;j<=(X+off);j++){
				if(!dp2[i][j]){
					continue;
				}
				int cur=in[k];
				//joins unfinished team
				dp1[i][j]+=i*dp2[i][j];
				dp1[i][j]%=MOD;
				
				//finishes team
				if(i>0 && (j+cur)<=(X+off))
					dp1[i-1][j+cur]+=i*dp2[i][j];
					dp1[i-1][j+cur]%=MOD;
				
				//creates team
				dp1[i+1][j-cur]+=dp2[i][j];
				dp1[i+1][j-cur]%=MOD;

				//creates and finishes team
				dp1[i][j]+=dp2[i][j];
				dp1[i][j]%=MOD;

			}
		}
		FOR0(i,N+2){
			FOR0(j,X+off+1){
				dp2[i][j]=(dp1[i][j]%MOD);
				dp1[i][j]=0;
			}
		}
	}

	int ans=0;
	for(int i=off;i<=(off+X);i++){
		ans+=dp2[0][i];
		ans%=MOD;
	}
	cout<<ans<<endl;




	return 0;
}
