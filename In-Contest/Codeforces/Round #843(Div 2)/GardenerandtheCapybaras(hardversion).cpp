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
							if(curA.at(i)<curB.at(i)){
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
		if(N==1 || N==2){
 
			cout<<": ("<<endl;
			continue;
		}
		if(in.at(0)==in.at(1)){
			cout<<in.at(0)<<" "<<in.at(1)<<" ";
			FOR(i,2,N){
				cout<<in.at(i);
			}
			cout<<endl;
			continue;
		}
		if(in.at(0)=='a'){
			if(in.at(2)=='a'){
				cout<<in.at(0)<<" "<<in.at(1)<<" ";
				FOR(i,2,N){
					cout<<in.at(i);
				}
				cout<<endl;
				continue;
			}else{
				
				bool found=false;
				if(N==3){
					cout<<in.at(0)<<" "<<in.at(1)<<" "<<in.at(2)<<endl;
					continue;
				}
				string b="bb";
				string c="";
				bool onC=false;
				for(int i=3;i<=(N-1);i++){
					if(onC){
						c.pb(in.at(i));
						continue;
					}
					if(in.at(i)=='a'){
						c.pb(in.at(i));
						onC=true;
						continue;
					}
					b.pb('b');
				}
				if(onC){
					cout<<'a'<<' '<<b<<" "<<c<<endl;
				}else{
					cout<<'a'<<" ";
					for(int i=1;i<=N-2;i++){
						cout<<"b";
					}
					cout<<" b"<<endl;;
					continue;
				}
 
			}
		}else{
			cout<<"b a ";
			FOR(i,2,N){
					cout<<in.at(i);
			}
				cout<<endl;
				continue;
		}
	}
 
 
	return 0;
}
