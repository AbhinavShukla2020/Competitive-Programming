#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
long long N;

void fileIO(string filename) {
    freopen((filename + ".in").c_str(), "r", stdin);
    freopen((filename + ".out").c_str(), "w", stdout);
}

int main() {
    fileIO("moop");
    cin>>N;
    vector<pair<long long,long long>> points(N);
    for(long long i=0;i<N;i++){
        cin>>points[i].first>>points[i].second;
    }

    sort(points.begin(),points.end());
    vector<long long> backYMax;
    backYMax.push_back(-10000000000000000);
    for(long long i=N-1;i>=0;i--){
        if(backYMax.size()!=0){
            backYMax.push_back(max(backYMax[backYMax.size()-1],points[i].second));
        }
    }


    long long curMin=100000000000000;
    long long ans=0;
    for(long long i=0;i<N;i++){
        long long cy=points[i].second;
        if(curMin>backYMax[N-i]){
            ans++;
        }
        curMin=min(curMin,cy);
    }
    cout<<ans;

    return 0;
}
