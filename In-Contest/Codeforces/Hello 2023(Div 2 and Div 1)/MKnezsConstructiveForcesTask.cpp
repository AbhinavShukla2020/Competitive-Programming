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
		if(N==3){
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
		if(N%2==0){
			FOR0(i,N){
				if(i%2==0){
					cout<<-1<<" ";
				}else{
					cout<<1<<" ";
				}
			}
			cout<<endl;
		}else{
			int neg=N/2;
			int pos=neg-1;
			neg=-neg;
			FOR0(i,N){
				if(i%2==0){
					cout<<pos<<" ";
				}else{
					cout<<neg<<" ";
				}
			}
			cout<<endl;
		}
	}


	return 0;
}
