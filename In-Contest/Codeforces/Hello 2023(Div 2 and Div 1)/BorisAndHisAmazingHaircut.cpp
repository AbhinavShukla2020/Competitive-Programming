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
	FOR0(t,T){
		int N;
		cin>>N;
		vector<int> cur(N);
		vector<int> des(N);
		FOR0(i,N){
			cin>>cur[i];
		}
		FOR0(i,N){
			cin>>des[i];
		}
		map<int,int> razors;
		int K;
		cin>>K;
		FOR0(i,K){
			int a;
			cin>>a;
			razors[a]++;
		}
		multiset<int> curRazors;
		bool works=true;
		FOR0(i,N){
			if(cur[i]<des[i]){works=false; break;}

			while(!curRazors.empty() && *curRazors.begin()<des[i]){
				curRazors.erase(curRazors.begin());
			}
			if(cur[i]==des[i]){
				continue;
			}
			if(curRazors.find(des[i])!=curRazors.end()){
				continue;
			}
			if(razors[des[i]]>0){
				curRazors.insert(des[i]);
				razors[des[i]]--;
			}else{
				works=false;
				break;
			}
		}
		if(works){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}


	return 0;
}
