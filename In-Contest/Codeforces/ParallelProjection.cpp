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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--){
		int w,d,h;
		int a,b,f,g;
		cin>>w>>d>>h>>a>>b>>f>>g;
		int ans1=abs(a-f)+h+min(abs(b+g),abs(d-b+d-g));
		int ans2=abs(b-g)+h+min(abs(a+f),abs(w-a+w-f));
		cout<<min(ans1,ans2)<<endl;
	}


	return 0;
}
