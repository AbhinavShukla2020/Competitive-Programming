#include <iostream>
#include <vector>
#include <set>
#include <bits/stdc++.h>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <cassert>
#include <math.h>
 
using namespace std;
 
using pii = pair<int,int>;
using vi = vector<int>;

#define endl "\n"
#define int int64_t 
#define double long double
#define pb push_back
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR0(i,a) FOR(i,0,a)
#define FOR1(i,a) for (int i = (1); i <= (a); ++i)
#define TRAV(a,x) for (auto& a: x)

vector<int> coords;
vector<int> speeds;
int N;

bool f(double mtime){
	vector<pair<double,double>> intervals;
	FOR0(i,N){
		intervals.pb({coords[i]-speeds[i]*mtime,coords[i]+speeds[i]*mtime});
	}
	sort(intervals.begin(),intervals.end());
	double low=-10000000000000.0;
	double high=10000000000000.0;
	TRAV(i,intervals){
		//cout<<"i: "<<i.first<<" "<<i.second<<endl;
		//cout<<low<<" "<<high<<endl;
		if(i.second<low){
			return false;
		}
		if(i.first>high){
			return false;
		}
		low=max(low,i.first);
		high=min(high,i.second);
	}
	return true;
}

double first_true(double lo,double hi) {
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
	cin>>N;
	FOR0(i,N){
		int a;
		cin>>a;
		coords.pb(a);
	}
	FOR0(i,N){
		int a;
		cin>>a;
		speeds.pb(a);
	}
	// cout<<f(2)<<endl;
	// return 0;
	double high=first_true(0,100000000000);
	double low=high-1;
	//cout<<low<<endl;
	double ans;
	FOR0(i,20){
		//cout<<ans<<endl;
		double mid=(low+high)/2;
		if(f(mid)){
			ans=mid;
			high=mid;
		}else{
			ans=mid;
			low=mid;
		}
	}
	cout<<setprecision(10)<<ans<<endl;


	return 0;
}
