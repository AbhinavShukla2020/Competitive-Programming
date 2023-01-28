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
		map<int,int> freq;
		set<int> nums;
		FOR0(i,N){
			int a;
			cin>>a;
			nums.insert(a);
			freq[a]++;
		}
		vi numsV;
		TRAV(i,nums){
			numsV.pb(i);
		}
		vector<vector<int>> seq;
		map<int,pii> pos;
		for(int i=0;i<nums.size();i++){
			vector<int> cur;
			cur.pb(numsV[i]);
			int copy=i;
			for(int j=copy+1;j<nums.size();j++){
				if(numsV[j]==(*cur.rbegin()+1)){
					cur.pb(numsV[j]);
					i++;
				}else{
					break;
				}
			}
			
			for(int j=0;j<cur.size();j++){
				pos[cur[j]]={seq.size(),j};
			}
			seq.pb(cur);
			
		}

		int ans=0;
		TRAV(i,nums){
			if(freq[i]==0){
				continue;
			}
			while(freq[i]!=0){
				freq[i]--;
				for(int j=pos[i].second+1;j<seq[pos[i].first].size();j++){
					if(freq[seq[pos[i].first][j]]>0){
						freq[seq[pos[i].first][j]]--;
					}else{
						break;
					}
				}
				ans++;
			}

		}
		cout<<ans<<endl;
	}


	return 0;
}
