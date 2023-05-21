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

int32_t main(){
	int T;
	cin>>T;
	while(T--){
		int N;
		cin>>N;
		vi in(N);
		bool found=false;
		int smallest=100000000000000009;
		bool paritySame=true;
		FOR0(i,N){
			cin>>in[i];
			if(i>0){
				if((in[i]%2)!=(in[i-1]%2)){
					paritySame=false;
				}
			}
			if((in[i]%2)==1){
				found=true;
				smallest=min(smallest,in[i]);
			}
		}
		if(paritySame){
			cout<<"YES"<<endl;
			continue;
		}

		//case 1:
		bool works=true;
		FOR0(i,N){
			if((in[i]%2)==1 && smallest>=in[i]){
				works=false;
			}
		}



		//case 2:
		bool works2=true;
		FOR0(i,N){
			if((in[i]%2)==0 && smallest>=in[i]){
				works2=false;
			}
		}

		if(works || works2){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}







}
