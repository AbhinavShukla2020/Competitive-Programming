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
		vector<int> in(N);
		FOR0(i,N){
			cin>>in[i];
		}
		if(N==1){
			cout<<0<<endl;
			continue;
		}
		int ans=0;
		FOR0(i,N){
			int curPar=(in[i] % 2);
			int counter=1;
			for(int j=i+1;j<N;j++){
				if((in[j]%2)==curPar){
					counter++;
					i++;
				}else{
					break;
				}
			}
			ans+=(counter-1);
		}
		cout<<ans<<endl;
	}


	return 0;
}
