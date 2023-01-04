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
		int N,M;
		cin>>N>>M;
		M--;
		vi nums(N);
		FOR0(i,N){
			cin>>nums[i];
		}

		int ans=0;
		int curSum=0;
		priority_queue<int> cur;
		for(int i=M;i>=1;i--){
			curSum+=nums[i];
			cur.push(nums[i]);
			if(curSum>0){
				curSum-=(cur.top()*2);
				cur.pop();
				ans++;
			}
		} 
		
		curSum=0;
		priority_queue<int> cur2;
		for(int i=M+1;i<N;i++){
			curSum+=nums[i];
			cur2.push(-nums[i]);
			if(curSum<0){
				curSum+=(cur2.top()*2);
				cur2.pop();
				ans++;
			}
		}
		cout<<ans<<endl;
	}


	return 0;
}
