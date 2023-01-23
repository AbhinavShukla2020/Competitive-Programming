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

vi getDivs(int n)
{
    vi ans;
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
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

int min(int a,int b){
	if(a<b){
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
		int N,M;
		cin>>N>>M;
		vi in(N);
		FOR0(i,N){
			cin>>in[i];
		}
		sort(in.begin(),in.end());
		int r=0;
		int ans=10000000;
		int cur=0;
		int freq[M+1];
		for(int i=0;i<=M;i++){
			freq[i]=0;
		}
		for(int l=0;l<N;l++){
			while(cur!=M && r<N){
				vi divs=getDivs(in[r]);
				TRAV(i,divs){
					if(i>M){continue;}
					freq[i]++;
					if(freq[i]==1){
						cur++;
					}
				}
				r++;

			}

			if(cur==M){
				ans=min(ans,in[r-1]-in[l]);
			}

			vi divs=getDivs(in[l]);
			TRAV(i,divs){
				if(i>M){continue;}
				freq[i]--;
				if(freq[i]==0){
					cur--;
				}
			}

		}
		if(ans==10000000){
			cout<<-1<<endl;
			continue;
		}
		cout<<ans<<endl;
	}


	return 0;
}
