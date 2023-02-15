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

struct point{
	int q,t,x,n;
};

bool cmp(point a, point b){
	if((a.t+a.x)==(b.t+b.x)){
		return (a.t-a.x)<(b.t-b.x);
	}
	return (a.t+a.x)<(b.t+b.x);
}

bool cmp2(point a, point b){
	return (a.t-a.x)>(b.t-b.x);
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin>>N;
	vector<point> in;
	FOR0(i,N){
		int q,t,x,n;
		cin>>q>>t>>x>>n;
		in.pb({q,t,x,n});
	}
	sort(in.begin(),in.end(),cmp);
	set<point,decltype(&cmp2)> cur(cmp2);
	int ans=0;
	TRAV(i,in){
		if(i.q==1){
			cur.insert(i);
		}else{
			int left=i.n;
			while(true){
				if(cur.empty()){
					break;
				}
				auto it=cur.lower_bound(i);
				if(it==cur.end()){
					break;
				}
				int get=min((*it).n,left);
				ans+=get;
				if((*it).n>left){
					int q1=(*it).t, t1=(*it).t, x1=(*it).x,n1=(((*it).n)-left); 
					cur.erase(it);
					cur.insert({q1,t1,x1,n1});
					break;
				}
				left-=get;
				cur.erase(it);
			}
		}
	}
	cout<<ans<<endl;

	return 0;
}
