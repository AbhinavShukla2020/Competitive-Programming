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

const int MAXN=3e5+1;
int N,M;
int nums[MAXN][8];
set<int> act;
vector<pair<vector<int>,vector<int>>> subsets;
vector<int> act2;

vector<vector<int>> getSubsets(const vector<int>& in){
    vector<vector<int>> ans={{}};
    for(const int &i : in){
        ans.resize(2*ans.size());
        for(int j=0;j<ans.size()/2;j++){
            ans[ans.size()/2+j]=ans[j];
            ans[ans.size()/2+j].push_back(i);
        }
    }
    return ans;
}

pii f(int n){
	map<vector<int>,int> cnt;
	FOR0(i,N){
		vector<int> cur;
		FOR0(j,M){
			if(nums[i][j]>=n){
				cur.pb(j);
			}
		}
		cnt[cur]++;
	}
	TRAV(k,subsets){
		if(cnt[k.first]>=1 && cnt[k.second]>=1){
			pii ans={-2,-2};
			FOR0(i,N){
				vector<int> cur;
				FOR0(j,M){
					if(nums[i][j]>=n){
						cur.pb(j);
					}
				}	
				if(k.first==cur){
					ans.first=i+1;
				}
				if(k.second==cur){
					ans.second=i+1;
				}
		
			}
			return ans;
		}
	}
	return {-1,-1};

}

pii last_true(int lo, int hi) {
	lo--;
	while (lo < hi) {
		int mid = lo + (hi - lo + 1) / 2;
		if (f(act2[mid]).first!=-1) {
			lo = mid;
		} else {
			hi = mid - 1;
		}
	}
	return f(act2[lo]);
}


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>M;
	FOR0(i,N){
		FOR0(j,M){
			cin>>nums[i][j];
			act.insert(nums[i][j]);
		}
	}
	TRAV(i,act){
		act2.pb(i);
	}
	sort(act2.begin(),act2.end());
	vector<int> eroe;
	FOR0(i,M){
		eroe.pb(i);
	}
	vector<vector<int>> sub=getSubsets(eroe);
	TRAV(i,sub){
		TRAV(j,sub){
			unordered_set<int> used;
			TRAV(k,i){
				used.insert(k);
			}
			TRAV(k,j){
				used.insert(k);
			}
			if(used.size()==M){
				subsets.pb({i,j});
			}
		}
	}
	pii ans=last_true(0,act2.size()-1);
	cout<<ans.first<<" "<<ans.second<<endl;
	return 0;
}
