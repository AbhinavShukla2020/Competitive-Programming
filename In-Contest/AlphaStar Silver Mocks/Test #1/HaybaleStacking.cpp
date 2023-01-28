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

int N,M;
vi in2;
map<int,int> freq;

int closestE(const map<int,int>& in, int a){
	if(a>(*in.rbegin()).first){
		return (*in.rbegin()).first;
	}
	if(a<(*in.begin()).first){
		return -1;
	}
	auto it=in.upper_bound(a);
	it--;
	return (*it).first;
}

bool f2(int h){
	map<int,int> curFreq=freq;
	bool vis[1000000+1];
	FOR0(i,1000000+1){
		vis[i]=false;
	}
	int cur=0;
	
	TRAV(i,in2){
		if(curFreq[i]>0){
			int curTot=i;
			while(curTot<=h && closestE(curFreq,h-curTot)!=-1){
				cout<<"hi"<<endl;
				curFreq[closestE(curFreq,h-curTot)]--;
				curTot+=closestE(curFreq,h-curTot);
				if(curFreq[closestE(curFreq,h-i)]==0){
					curFreq.erase(closestE(curFreq,h-i));
				}
			}
			cur++;
		}
	}
	cout<<cur<<endl;
	if(cur<=M){
		return true;
	}
	return false;
}

bool f(int h){
	int ans=0;
	for(int i=0;i<N;){
		//cout<<endl<<endl<<i<<endl;
		ans++;
		int curTot=0;
		int past=1000000000000;
		int copt=i;
		for(int j=copt;j<N;j++){
			//cout<<in2[j]<<" "<<curTot<<" "<<past<<endl;
			if((curTot+in2[j])>h){
				//cout<<j<<" "<<in2[j]<<endl;
				//i++;
				break;
			}
			if(in2[j]<=past){
				past=in2[j];
				curTot+=in2[j];
				i++;
			}else{
				break;
			}
		}
	}
	if(ans<=M){
		return true;
	}else{
		return false;
	}
}
int first_true(int lo, int hi) {
	hi++;
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (f(mid)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}
int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>N>>M;
	
	//return 1;
	FOR0(i,N){
		int a;
		cin>>a;
		in2.pb(a);
		//freq[a]++;
	}	
	if(first_true(1,10000000000000)==10000000000001){
		cout<<"IMPOSSIBLE"<<endl;
		return 0;
	}
	cout<<first_true(1,10000000000000);

	return 0;
}
