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

const int MOD=1000000000+7;
int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--){
		int N;
		cin>>N;
		string A2,B2;
		cin>>A2>>B2;
		string A="",B="";
		FOR0(i,N){
			if(A2.at(i)=='0'){
				A="*";
			}else if(A2.at(i)=='+'){
				A.pb(A2.at(i));
			}else if(A2.at(i)!='1'){
				A.pb('*');
			}

			if(B2.at(i)=='0'){
				B="*";
			}else if(B2.at(i)=='+'){
				B.pb(B2.at(i));
			}else if(B2.at(i)!='1'){
				B.pb('*');
			}
		}
		A.insert(0," ");
		B.insert(0," ");
		int dp[A.size()+1][B.size()+1][2];
		FOR0(i,A.size()+1){
			FOR0(j,B.size()+1){
				dp[i][j][0]=0;
				dp[i][j][1]=0;
			}
		}
		dp[0][0][1]=1;
		FOR0(i,A.size()){
			FOR0(j,B.size()){
				if((j+1)<B.size()){
					dp[i][j+1][1]=(dp[i][j][1]+dp[i][j][0])%MOD;
				}
				if((i+1)<A.size()){
					if(B.at(j)==A.at(i+1)){
						dp[i+1][j][0]=dp[i][j][0];
					}else{
						dp[i+1][j][0]=(dp[i][j][0]+dp[i][j][1])%MOD;
					}
				}

			}
		}
		cout<<(dp[A.size()-1][B.size()-1][0]+dp[A.size()-1][B.size()-1][1])%MOD<<endl;
	}


	return 0;
}
