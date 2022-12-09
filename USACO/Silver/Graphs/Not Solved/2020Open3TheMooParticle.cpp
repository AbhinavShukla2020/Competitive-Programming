#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
long long N;
void fileIO(string filename) {
    freopen((filename + ".in").c_str(), "r", stdin);
    freopen((filename + ".out").c_str(), "w", stdout);
}
int main() {
    fileIO("moop");
    cin>>N;
    vector<pair<long long,long long>> x;
    vector<long long> y;
    for(long long i=0;i<N;i++){
        long long a,b;
        cin>>a>>b;
        x.push_back({a,b});
    }

    sort(x.begin(),x.end());
    vector<long long> backYMax;
    backYMax.push_back(-10000000000000000);
    for(long long i=N-1;i>=0;i--){
        y.push_back(x[i].second);
        if(backYMax.size()!=0){
            backYMax.push_back(max(backYMax[backYMax.size()-1],x[i].second));
        }else{
            backYMax.push_back(x[i].second);
        }
    }

    set<long long> curY;
    curY.insert(100000000000000);
    long long ans=0;
    for(long long i=0;i<N;i++){
        long long cy=x[i].second;
        if(*curY.begin()>cy && *curY.begin()>backYMax[N-i-1]){
            ans++;
        }
        curY.insert(cy);
    }
    cout<<ans;

    return 0;
}
