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

const int MOD=998244353;
const int MAXN=3e5+1;
int fact[MAXN];
int powmod(int a, int b, int p){
    a %= p;
    if (a == 0) return 0;
    int product = 1;
    while(b > 0){
        if (b&1){    // you can also use b % 2 == 1
            product *= a;
            product %= p;
            --b;
        }
        a *= a;
        a %= p;
        b /= 2;    // you can also use b >> 1
    }
    return product;
}

int inv(int a, int p){
    return powmod(a, p-2, p);
}

int nCk(int n, int k, int p){
    return ((fact[n] * inv(fact[k], p) % p) * inv(fact[n-k], p)) % p;
}


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	fact[1]=1;
	for(int i=2;i<=300000;i++){
		fact[i]=fact[i-1]*i;
		fact[i]=fact[i]%MOD;
	}
	int N;
	cin>>N;
	int ans=1;
	int n=N/3;
	ans*=nCk(n,n/2,MOD);
	FOR0(i,N/3){
		vector<int> cur;
		int a,b,c;
		cin>>a>>b>>c;
		cur.pb(a);
		cur.pb(b);
		cur.pb(c);
		sort(cur.begin(),cur.end());
		a=cur[2];
		b=cur[1];
		c=cur[0];
		if(a==b && a==c && b==c){
			ans*=3;
			ans=ans%MOD;
			continue;
		}
		if(b==c){
			ans*=2;
			ans=ans%MOD;
			continue;
		}
	}
	ans=ans%MOD;
	cout<<ans<<endl;



	return 0;
}
