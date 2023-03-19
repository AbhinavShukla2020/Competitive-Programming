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



int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--){
		int N;
		cin>>N;
		string in;
		cin>>in;
		map<char,int> pos;
		bool works=true;
		FOR0(i,N){
			if(pos.find(in.at(i))==pos.end()){
				pos[in.at(i)]=i;
			}else{
				int a=pos[in.at(i)]%2;
				int b=i%2;
				if(a!=b){
					works=false;
				}
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
