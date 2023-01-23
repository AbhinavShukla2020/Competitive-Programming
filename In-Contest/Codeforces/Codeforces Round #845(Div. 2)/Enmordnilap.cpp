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



int32_t main(){
	set<map<int,int>> h;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--){
		int N;
		cin>>N;
		int ans=1;
		int curFrac=1;
		FOR1(i,N){
			curFrac=curFrac*i;
			curFrac=(curFrac)%(1000000000+7);
		}
		curFrac=curFrac*(N-1);
		curFrac=curFrac%(1000000000+7);
		curFrac=curFrac*(N);
		curFrac=(curFrac)%(1000000000+7);
		cout<<curFrac<<endl;
	}


	return 0;
}
