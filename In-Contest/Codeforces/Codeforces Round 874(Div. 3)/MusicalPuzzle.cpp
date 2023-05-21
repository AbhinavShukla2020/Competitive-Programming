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
	int T;
	cin>>T;
	while(T--){
		int N;
		cin>>N;
		string a;
		cin>>a;
		set<string> used;
		string first;
		first.pb(a.at(0));
		first.pb(a.at(1));
		used.insert(first);
		FOR(i,2,N){
			string needed;
			needed.pb(a.at(i-1));
			needed.pb(a.at(i));
			if(used.find(needed)==used.end()){
				used.insert(needed);
			}
		}
		cout<<used.size()<<endl;




	}







}
