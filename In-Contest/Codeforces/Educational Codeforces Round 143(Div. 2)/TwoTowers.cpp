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

bool isBeut(string a){
	char should=a.at(0);
	for(int i=0;i<a.size();i++){
		if(a.at(i)!=should){
			return false;
		}else{
			if(should=='B'){
				should='R';
			}else{
				should='B';
			}
		}
	}
	return true;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--){
		int N,M;
		cin>>N>>M;
		string a,b;
		cin>>a>>b;
		bool beut1=isBeut(a);
		bool beut2=isBeut(b);
		if(beut1 && beut2){
			cout<<"YES"<<endl;
			continue;
		}
		if(!beut1 && !beut2){
			cout<<"NO"<<endl;
			continue;
		}
		if(!beut1){
			string copy=a;
			a=b;
			b=copy;
		}
	//	cout<<"before: "<<a<<" "<<b<<endl;
		while(b.size()>1 && !isBeut(b)){
			a.pb(b.at(b.size()-1));
			b.pop_back();
		}
	//	cout<<a<<" "<<b<<endl;
		if(isBeut(a) && isBeut(b)){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
		// string n;
		// FOR0(i,b.size()-1){
		// 	n.pb(b.at(i));
		// }
		// if(!isBeut(n)){
		// 	cout<<"NO"<<endl;
		// 	continue;
		// }
		// cout<<"yo"<<endl;
		// if(a.at(a.size()-1)!=b.at(b.size()-1)){
		// 	cout<<"YES"<<endl;
		// }else{
		// 	cout<<"NO"<<endl;
		// }
	}


	return 0;
}
