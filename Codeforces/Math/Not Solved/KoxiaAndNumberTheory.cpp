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
using vi = vector<int>;
using vl = vector<ll>;

#define pb push_back
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR0(i,a) FOR(i,0,a)
#define FOR1(i,a) for (int i = (1); i <= (a); ++i)
#define TRAV(a,x) for (auto& a: x)



int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll T;
	cin>>T;
	FOR0(t,T){
		int N; cin>>N;
		vl nums(N);
		set<int> nums2;
		FOR0(i,N){
			cin>>nums[i];
			nums2.insert(nums[i]);
		}
		if(nums2.size()!=N){
			cout<<"NO"<<endl;
			continue;
		}
		bool ans=true;
		FOR(i,2,N/2+1){
			vl cnt(i,0);
			TRAV(j,nums){
				cnt[j%i]++;
			}
			bool curAns=false;
			FOR0(j,i){
				if(cnt[j]<2){
					curAns=true;
				}
			}
			if(!curAns){
				// cout<<i<<endl;
				ans=false;
				break;
			}

		}
		cout<<(ans ? "YES" : "NO")<<endl;
	}


	return 0;
}
