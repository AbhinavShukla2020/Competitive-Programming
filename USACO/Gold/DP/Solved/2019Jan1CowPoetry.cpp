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

int max(int a,int b){
	if(a>b){
		return a;
	}
	return b;
}
const int MOD=1000000007;
int dp[50001];
void fileIO(string filename) {
  freopen((filename + ".in").c_str(), "r", stdin);
  freopen((filename + ".out").c_str(), "w", stdout);
}

int32_t main() {
  	fileIO("poetry");
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N,M,K;
	cin>>N>>M>>K;
	map<int,vi> classes;
	vector<int> words;
	FOR0(i,N){
		int a,b;
		cin>>a>>b;
		classes[b].pb(a);
		words.pb(a);
	}

	

	dp[0]=1;

	FOR1(i,K){
		TRAV(j,words){
			if(i>=j){
				dp[i]+=dp[max(0,i-j)];
				dp[i]%=MOD;
			}
		}
		//cout<<i<<" "<<dp[i]<<endl;
	}

	map<char,int> rhymes;
	FOR0(i,M){
		char a;
		cin>>a;
		rhymes[a]++;
	}

	map<int,int> classVal;
	TRAV(i,classes){
			int cnt=0;
			TRAV(k,i.second){
				cnt+=dp[K-k];
			}
			cnt=cnt%MOD;
			classVal[i.first]=cnt;
	}

	int ans=1;
	TRAV(j,rhymes){
		int curAns=0;
		TRAV(i,classes){
			// int cnt=0;
			// TRAV(k,i.second){
			// 	cnt+=dp[K-k];
			// }
			// cnt=cnt%MOD;
			int cnt=classVal[i.first];
			int val=1;
			for(int k=1;k<=j.second;k++){
				val*=cnt;
				val%=MOD;
			}
			curAns+=val;
			curAns%=MOD;
			
		}
		ans*=curAns;
		ans%=MOD;
	}
	cout<<ans<<endl;



	return 0;
}
