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
		vector<vi> perms;
		map<int,int> cnt;
		FOR0(i,N){
			cnt[i]=0;
			vi in;
			FOR0(j,N-1){
				int k;
				cin>>k;
				in.pb(k);
			}
			perms.pb(in);
		}
		vi ans;
		FOR0(i,N-1){
			map<int,int> freq;
			TRAV(j,cnt){
				freq[perms[j.first][j.second]]++;
			}
			int bad=0;
			TRAV(j,freq){
				if(j.second==1){
					bad=j.first;
					break;
				}
			}
			ans.pb(bad);
			FOR0(j,N){
				if(perms[j][cnt[j]]!=bad){
					cnt[j]++;
				}
			}

		}
		bool vis[N+1];
		for(int i=1;i<=N;i++){
			vis[i]=false;
		}
		TRAV(i,ans){
			vis[i]=true;
		}
		for(int i=1;i<=N;i++){
			if(vis[i]==false){
				cout<<i<<" ";
			}
		}
		TRAV(i,ans){
			cout<<i<<" ";
		}
		cout<<endl;



	}


	return 0;
}
