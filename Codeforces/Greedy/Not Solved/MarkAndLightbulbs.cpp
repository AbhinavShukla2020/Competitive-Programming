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
	while(T--){
		int N;
		cin>>N;
		string a,b;
		cin>>a>>b;
		if(a.at(0)!=b.at(0) || a.at(N-1)!=b.at(N-1)){
			cout<<-1<<endl;
			continue;
		}
		vector<int> sub1;
		vector<int> sub2;
		for(int i=0;i<N;i++){
			char cur=a.at(i);
			while((i+1)<N && a.at(i+1)==cur){
				i++;
			}
			sub1.pb(i);
		}
	
		cout<<endl;
		for(int i=0;i<N;i++){
			char cur=b.at(i);
			while((i+1)<N && b.at(i+1)==cur){
				i++;
			}
			sub2.pb(i);
		}
		
		cout<<endl;
		if(sub1.size()!=sub2.size()){cout<<-1<<endl; continue;}
		int ans=0;
		FOR0(i,sub1.size()){
			ans+=abs(sub1[i]-sub2[i]);
		}
		cout<<ans<<endl;
	
	}

	return 0;
}
