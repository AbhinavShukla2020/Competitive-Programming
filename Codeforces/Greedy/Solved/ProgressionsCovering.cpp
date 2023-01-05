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
	int N,K;
	cin>>N>>K;
	vector<int> nums(N);
	vector<int> curNums(N,0);
	vector<int> inc(N,0);
	FOR0(i,N){
		cin>>nums[i];
	}
	
	int curCounter=0;
	int curSum=0;
	int ans=0;
	for(int i=N-1;i>=0;i--){
		curSum-=curCounter;
		curCounter-=inc[i];
		curNums[i]=curSum;
		if(curNums[i]<nums[i] && i>=(K-1)){
			int amoRepsNeeded=(nums[i]-curNums[i])/K;
			if((nums[i]-curNums[i])%K!=0){
				amoRepsNeeded++;
			}
			if(i-K>=0){
				inc[i-K]+=amoRepsNeeded;
			}
			curSum+=(amoRepsNeeded*K);
			curNums[i]+=(amoRepsNeeded*K);
			ans+=amoRepsNeeded;
			curCounter+=amoRepsNeeded;
		}
	}
	
	int newAns=0;
	FOR0(i,K){
		if(curNums[i]>=nums[i]){continue;}
		int cur=(nums[i]-curNums[i])/(i+1);
		if((nums[i]-curNums[i])%(i+1)!=0){
				cur++;
		}
		newAns=max(newAns,cur);
	}
	cout<<ans+newAns<<endl;


	return 0;
}
