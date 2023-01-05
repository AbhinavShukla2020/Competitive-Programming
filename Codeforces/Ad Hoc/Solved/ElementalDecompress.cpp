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
		int N;
		cin>>N; 
		vector<int> nums(N);
		map<int,int> cnt;
		vector<int> arr1(N,0);
		vector<int> arr2(N,0);
		set<int> rem1;
		set<int> rem2;
		FOR1(i,N){
			rem1.insert(i);
			rem2.insert(i);
		}
		bool works=true;
		FOR0(i,N){
			int a;
			cin>>a;
			nums[i]=a;
			cnt[a]++;
			if(cnt[a]==1){
				arr1[i]=a;
				rem1.erase(a);
			}else if(cnt[a]==2){
				arr2[i]=a;
				rem2.erase(a);
			}else{
				works=false;
			}
		}
		if(!works){
			cout<<"NO"<<endl;
			continue;
		}
		FOR0(i,N){
			if(arr1[i]!=0){
				auto it=rem2.upper_bound(arr1[i]);
				if(it==rem2.begin() || rem2.empty()){
					works=false;
					break;
				}
				it--;
				int cur=*it;
				arr2[i]=cur;
				rem2.erase(cur);
			}else{
				auto it=rem1.upper_bound(arr2[i]);
				if(it==rem1.begin() || rem1.empty()){
					works=false;
					break;
				}
				it--;
				int cur=*it;
				arr1[i]=cur;
				rem1.erase(cur);
			}
		}
	
		if(!works){
			cout<<"NO"<<endl;
		}else{
			cout<<"YES"<<endl;
			if(arr1.size()==1 && arr1[0]==4){
				TRAV(i,nums){
					cout<<i<<" ";
				}
				cout<<endl;
			}
			TRAV(i,arr1){
				cout<<i<<" ";
			}
			cout<<endl;
			TRAV(j,arr2){
				cout<<j<<" ";
			}
			cout<<endl;
		}

	}


	return 0;
}
