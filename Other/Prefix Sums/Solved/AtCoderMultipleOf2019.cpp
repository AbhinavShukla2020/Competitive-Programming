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

int nthDigit(string v, int n)
{
	return int(v.at(n)-'0');
    
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	cin>>S;
	vector<int> pow10(2000002);
	pow10[0]=1;
	for(int i=1;i<=2000001;i++){
		pow10[i]=(pow10[i-1]*10+2019)%2019;
	}

	int N=S.size();
	map<int,int> occ;
	int curRem=0;
	int curlength=0;
	int ans=0;
	//cout<<N<<endl;
	//cout<<"test: "<<int(nthDigit(S,N-1)-'0')<<endl;
	occ[0]++;
	for(int i=(N-1);i>=0;i--){
		curRem+=pow10[N-1-i]*nthDigit(S,i);
		//cout<<" "<<nthDigit(S,i)<<endl;
		
		//curRem%=2019;
		curRem=(((curRem+2019)%2019)+2019)%2019;
		//cout<<curRem<<" "<<(curRem)<<endl;
		ans+=occ[curRem];
		if(occ[curRem]>0){
		//	cout<<"          "<<occ[curRem]<<endl;
		}
		occ[curRem]++;
		curlength++;
	}
	cout<<ans<<endl;


	return 0;
}
