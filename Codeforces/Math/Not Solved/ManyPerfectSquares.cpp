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

vector<int> getDivs(int n)
{
	vector<int> ans;
    // Note that this loop runs till square root
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            // If divisors are equal, print only one
            if (n/i == i)
                ans.pb(i);
  
            else{
               ans.pb(i);
               ans.pb(n/i);
            }
        }
    }
    return ans;
}
int max(int a,int b){
	if(a>b){
		return a;
	}
	return b;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--){
		int N;
		cin>>N;
		vector<int> in(N);
		FOR0(i,N){
			cin>>in[i];
		}
		sort(in.begin(),in.end());
		map<int,set<int>> cnt;
		FOR0(i,N){
			FOR(j,i+1,N){
				int diff=in[j]-in[i];
				vector<int> divs=getDivs(diff);
				TRAV(k,divs){
					if((k+diff/k)%2!=0){continue;}
					int curX=(k+diff/k)/2;
					int curY=curX-diff/k;
					if(curX>=0 && curY>=0 && curX*curX>=in[j] && curY*curY>=in[i]){
						cnt[abs(in[j]-curX*curX)].insert(i);
						cnt[abs(in[j]-curX*curX)].insert(j);
					}
				}
			}
		}
		int curAns=1;
		TRAV(i,cnt){ 
			curAns=max(curAns,i.second.size());
		}
		cout<<curAns<<endl;
	}


	return 0;
}
