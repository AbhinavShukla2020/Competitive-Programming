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
	while(T--){
		int N,K;
		cin>>N>>K;
		vi nums(N);
		map<int,int> pos;
		FOR0(i,N){
			cin>>nums[i];
			pos[nums[i]]=i;
		}
		pos[0]=-1;
		int counter=0;
		
		FOR1(i,N){
			if(pos[i]>pos[i-1]){
				counter++;
			}else{
				break;
			}
		}
		if((N-counter)%K==0){
			cout<<(N-counter)/K<<endl;
		}else{
			cout<<(N-counter)/K+1<<endl;
		}
	}


	return 0;
}
