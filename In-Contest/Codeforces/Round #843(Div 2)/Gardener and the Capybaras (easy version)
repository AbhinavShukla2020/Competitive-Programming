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
 
int check(string curA, string curB){
	bool prefix=true;
 
				for(int i=0;i<min(curA.size(),curB.size());i++){
					if(curA.at(i)!=curB.at(i)){
						prefix=false;
						break;
					}
				}
				if(prefix){
					if(curA==curB){
						return 3;
					}else{
						if(curA.size()<curB.size()){
							return 1;
						}else{
							return 2;
						}
					}
				}else{
					for(int i=0;i<min(curA.size(),curB.size());i++){
						if(curA.at(i)!=curB.at(i)){
							if(curA.at(i)=='a' && curB.at(i)=='b'){
								return 1;
								break;
							}else{
								return 2;
								break;
							}
						}	
					}
				}
}
 
int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--){
		string in;
		cin>>in;
		int N=in.size();
		bool done=false;
		for(int pointerA=0;pointerA<=N-3;pointerA++){
			for(int pointerB=pointerA+1;pointerB<=N-2;pointerB++){
				if(done){
					break;
				}
				string curA;
				string curB;
				string curC;
				for(int i=0;i<=pointerA;i++){
					curA.pb(in.at(i));
				}
				for(int i=pointerA+1;i<=pointerB;i++){
					curB.pb(in.at(i));
				}
				for(int i=pointerB+1;i<=N-1;i++){
					curC.pb(in.at(i));
				}
 
				int aOrb=check(curA,curB);
				int bOrC=check(curB,curC);
				if(aOrb==3 || bOrC==3){
					cout<<curA<<" "<<curB<<" "<<curC<<endl;
					done=true;
					break;
				}
				if(aOrb==2 && bOrC==1){
					cout<<curA<<" "<<curB<<" "<<curC<<endl;
					done=true;
					break;
				}
				if(aOrb==1 && bOrC==2){
					cout<<curA<<" "<<curB<<" "<<curC<<endl;
					done=true;
					break;
				}
				
 
			}
		}
		if(!done){
			cout<<": ("<<endl;
		}
	}
 
 
	return 0;
}
