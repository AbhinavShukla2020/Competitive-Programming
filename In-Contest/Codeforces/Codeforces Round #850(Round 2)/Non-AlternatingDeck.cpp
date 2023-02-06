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

bool f(int a,int b){
	if((b*b+b)<=a){
		return true;
	}
	return false;
}

int last_true(int lo, int hi,int n) {
	lo--;
	for (int dif = hi - lo; dif > 0; dif /= 2) {
		while (lo + dif <= hi && f(n,lo + dif)) {
			lo += dif;
		}
	}
	return lo;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--){
		int N;
		cin>>N;
		int counter1=0;
		int counter2=0;
		int cnt=1;
		while(N>0){
			//cout<<cnt<<" "<<counter1<<" "<<counter2<<endl;
			if(cnt==1){
				counter1++;
				N-=1;
				cnt++;
				continue;
			}
			if((cnt%4)==2 || (cnt%4)==3){
				if(cnt>N){
					counter2+=N;
					N=0;
					break;
				}
				counter2+=cnt;
				N-=cnt;
				cnt++;

			}else{
				if(cnt>N){
					counter1+=N;
					N=0;
					break;
				}
				counter1+=cnt;
				N-=cnt;
				cnt++;
			}
		}
		cout<<counter1<<" "<<counter2<<endl;

	}


	return 0;
}
