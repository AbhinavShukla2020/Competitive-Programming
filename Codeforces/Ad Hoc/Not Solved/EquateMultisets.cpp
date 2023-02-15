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
		int N;
		cin>>N;
		multiset<int> a;
		multiset<int> b;
		FOR0(i,N){
			int x;
			cin>>x;
			while(x%2==0){
				x/=2;
			}
			a.insert(x);
		}
		FOR0(i,N){
			int x;
			cin>>x;
			b.insert(x);
		}
		while(!b.empty()){
			int cur=(*b.begin()); // b.end() also works
			if(a.find(cur)!=a.end()){
				a.erase(a.find(cur));
				b.erase(b.find(cur));
			}else{
				if(cur==1){break;}
				b.insert(cur/2);
				b.erase(b.find(cur));
			}
		}
		if(b.empty()){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
