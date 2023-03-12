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
		int r,c;
		cin>>r>>c;
		int a=0,b=0;
		int ans=0;
		while(!(a==r && b==c)){
			if(a==r && b!=c){
				if(b<c){
					b++;
				}else{
					b--;
				}
				if(b==c){
					ans++;
					break;
				}else{
					ans+=2;
				}
			}else if(a!=r && b==c){
				if(a<r){
					a++;
				}else{
					a--;
				}
				if(a==r){
					ans++;
					break;
				}else{
					ans+=2;
				}
			}else{
				if(b<c){
					b++;
				}else{
					b--;
				}
				if(a<r){
					a++;
				}else{
					a--;
				}
				ans+=2;
			}
		}
		cout<<ans<<endl;
	}


	return 0;
}
