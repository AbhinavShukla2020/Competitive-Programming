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
		int N,Q;
		cin>>N>>Q;
		vector<int> in;
		int tot=0;
		FOR0(i,N){
			int a;
			cin>>a;
			tot+=a;
			in.pb(a);
		}
		int epsum[N+1];
		int opsum[N+1];
		for(int i=0;i<=N;i++){
			epsum[i]=0;
			opsum[i]=0;
		}
		FOR0(i,N){
			if(in[i]%2==0){
				epsum[i+1]++;
			}else{
				opsum[i+1]++;
			}
			epsum[i+1]+=epsum[i];
			opsum[i+1]+=opsum[i];
		}
		FOR0(i,Q){
			int l,r,k;
			cin>>l>>r>>k;
			l--;
			r--;
			int odds=opsum[r+1]-opsum[l];
			if(odds%2==0){
				bool change;
				if(k%2==0 || (r-l+1)%2==0){
					change=false;
				}else{
					change=true;
				}
				if(tot%2==0 && !change){
					cout<<"NO"<<endl;
				}else if(tot%2==0 && change){
					cout<<"YES"<<endl;
				}else if(tot%2==1 && change){
					cout<<"NO"<<endl;
				}else{
					cout<<"YES"<<endl;
				}

			}else{
				bool change;
				if(k%2==0 || (r-l+1)%2==0){
					change=false;
				}else{
					change=true;
				}
				if(tot%2==0 && !change){
					cout<<"YES"<<endl;
				}else if(tot%2==0 && change){
					cout<<"NO"<<endl;
				}else if(tot%2==1 && change){
					cout<<"YES"<<endl;
				}else{
					cout<<"NO"<<endl;
				}
			}
		}
	}


	return 0;
}
