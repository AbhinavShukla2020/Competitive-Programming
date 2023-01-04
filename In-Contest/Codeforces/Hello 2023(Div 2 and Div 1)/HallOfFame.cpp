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
		//cout<<"yo"<<endl;
		int N;
		cin>>N;
		string in1;
		cin>>in1;
		vector<char> in(in1.begin(),in1.end());
		int rightMostL=-100;
		int leftMostR=N+100;
		for(int i=N-1;i>=0;i--){
			if(in[i]=='L'){
				rightMostL=i;
				break;
			}
		}
		for(int i=0;i<N;i++){
			if(in[i]=='R'){
				leftMostR=i;
				break;
			}
		}
		//cout<<leftMostR<<" "<<rightMostL<<endl;
		if(rightMostL>leftMostR){
			cout<<0<<endl;
			continue;
		}
		if(abs(rightMostL-leftMostR)==1){
			cout<<min(rightMostL+1,leftMostR+1)<<endl;
			continue;
		}
		cout<<-1<<endl;

	}


	return 0;
}
