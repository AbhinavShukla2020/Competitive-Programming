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
	int N;
	cin>>N;
	vi in(N);
	FOR0(i,N){
		cin>>in[i];
	}
	int pointer=0;
	string ans;
	while(pointer!=N){
		queue<int> cur;
		int curPointer=pointer;
		if(in[curPointer]==2){
			in[curPointer]--;
			ans.pb('R');
			pointer++;
			continue;
		}
		
		while(curPointer<N && in[curPointer]!=2){
			cur.push(curPointer);
			curPointer++;
		}
		int curSize=cur.size();

		while(!cur.empty()){
			int k=cur.front();
			in[k]-=2;
			cur.pop();
		}
		
		for(int i=0;i<curSize;i++){
			ans.pb('R');
		}

		for(int i=0;i<curSize;i++){
			ans.pb('L');
		}

		
	}
	for(int i=0;i<N;i++){
		if(in[i]==1){
			ans.pb('L');
		}else{
			break;
		}
	}
	cout<<ans<<endl;

	return 0;
}
