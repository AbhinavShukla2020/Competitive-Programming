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

const int MAXN=1e4+5;

bool isPrime[MAXN+1];
vector<int> primes;

void fileIO(string filename) {
  freopen((filename + ".in").c_str(), "r", stdin);
  freopen((filename + ".out").c_str(), "w", stdout);
}

void getPrimes(){
  for(int i=0;i<=MAXN;i++){
    isPrime[i]=true;
  }
  for(int i=2;i<sqrt(MAXN);i++){
    if(isPrime[i]){
      for(int j=i*i;j<=MAXN;j+=i){
        isPrime[j]=false;
      }
    }
  }
  for(int i=2;i<=MAXN;i++){
    if(isPrime[i]){
      primes.push_back(i);
    }
  }
}

int32_t main(){
  fileIO("exercise");
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  getPrimes();
  int N,M;
  cin>>N>>M;
  int dp[1234][N+1];

  FOR0(i,N+1){
    dp[0][i]=1;
  }

  FOR1(j,primes.size()){
    int p=primes[j-1];

    FOR0(i,N+1){
      dp[j][i]=dp[j-1][i];

      int pp=p;
      while(pp<=i){
        dp[j][i]+=(dp[j-1][i-pp]*pp);
        dp[j][i]%=M;
        pp*=p;
      }
    }

  }

  cout<<dp[primes.size()-1][N]<<endl;
  return 0;
}
