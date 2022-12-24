#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>

using namespace std;

using ll = long long;
using pii = pair<ll,ll>;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin>>N;
	map<pii,int> diff;
	for(int i=1;i<=N;i++){
		for(int j=i;j<=N;j++){
			int a;
			cin>>a;
			diff[{i,j}]=a;
		}
	}

	vector<int> nums(N+1);
	nums[1]=0;
	for(int i=2;i<=N;i++){
		int cur=nums[i-1]+diff[{i-1,i}];
		nums[i]=cur;
		bool works=true;
		int curMin=nums[i];
		int curMax=nums[i];
		for(int j=i;j>=1;j--){
			curMin=min(nums[j],curMin);
			curMax=max(nums[j],curMax);
			if(diff[{j,i}]!=(curMax-curMin)){
				works=false;
			}
		}
		if(!works){
			nums[i]-=(2*diff[{i-1,i}]);
		}
	}
	for(int i=1;i<=N;i++){
		if(i!=N){		
			cout<<nums[i]<<" ";
		}else{
			cout<<nums[i];
		}
	}


	return 0;
}
