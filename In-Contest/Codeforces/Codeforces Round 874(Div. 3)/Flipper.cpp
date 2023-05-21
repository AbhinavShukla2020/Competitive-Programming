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
 


#define endl "\n"
#define int long long int
#define pb push_back
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR0(i,a) FOR(i,0,a)
#define FOR1(i,a) for (int i = (1); i <= (a); ++i)
#define TRAV(a,x) for (auto& a: x)

using pii = pair<int,int>;
using vi = vector<int>;
vi opp(vi in,int l, int r){
	vi ans;
	int N=in.size();
	for(int i=r+1;i<N;i++){
		ans.pb(in[i]);
	}
	vector<int> middle;
	for(int i=l;i<=r;i++){
		middle.pb(in[i]);
	}
	reverse(middle.begin(),middle.end());
	TRAV(i,middle){
		ans.pb(i);
	}
	FOR0(i,l){
		ans.pb(in[i]);
	}
	return ans;
}
int32_t main(){
	int T;
	cin>>T;
	while(T--){
		int N;
		cin>>N;
		vi in(N);
		int indN;
		int indNm;
		FOR0(i,N){
			cin>>in[i];
			if(in[i]==N){
				indN=i;
			}else if(in[i]==(N-1)){
				indNm=i;
			}
		}
		if(N==1){
			cout<<in[0]<<endl;
			continue;
		}
		int ind=indN-1;
		if(ind<0){
			ind=indNm-1;
		}
		vector<vector<int>> v;

		for(int l=(ind);l>=0;l--){
			v.pb(opp(in,l,ind));
		}
		for(int l=(ind+1);l>=0;l--){
			v.pb(opp(in,l,ind+1));
		}
		sort(v.begin(),v.end());

		TRAV(i,v[v.size()-1]){
			cout<<i<<" ";
		}
		cout<<endl;

	}







}
