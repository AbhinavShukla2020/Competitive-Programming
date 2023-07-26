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

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--){
		int N;
		cin>>N;
		vi in;
		vi ev;
		vi odd;
		FOR0(i,N){
			int a;
			cin>>a;
			in.pb(a);
			if((a%2)==0){
				ev.pb(a);
			}else{
				odd.pb(a);
			}
		}
		vi orig=in;
		sort(in.begin(),in.end());
		sort(ev.begin(),ev.end());
		sort(odd.begin(),odd.end());
		int Eind=0;
		int Oind=0;
		bool works=true;
		FOR0(i,N){
			if((orig[i]%2)==0 && in[i]==ev[Eind]){
				Eind++;
				continue;
			}
			if((orig[i]%2)==1 && in[i]==odd[Oind]){
				Oind++;
				continue;
			}
			//cout<<"i: "<<i<<endl;
			works=false;
			break;
		}
		if(works){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}

	}


	return 0;
}
