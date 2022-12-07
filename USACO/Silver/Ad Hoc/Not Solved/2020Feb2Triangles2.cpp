#include <iostream>
#include <vector>
#include <math.h>
#include <map>
#include <algorithm>
#include <set>
using namespace std;
using ll=long long;
ll N;
struct fence{
    ll heightSum;
    ll baseSum;
};
vector<fence> fences;
vector<pair<ll,ll>> xVals[20001];
vector<pair<ll,ll>> yVals[20001];
int main() {
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    cin>>N;
    for(ll i=0;i<N;i++){
        ll a,b;
        cin>>a>>b;
        a+=1e4;
        b+=1e4;
        xVals[a].push_back({b,i});
        yVals[b].push_back({a,i});
        fences.push_back({0,0});
    }

    for(ll i=0;i<=20000;i++){
        if(xVals[i].size()>0) {
            sort(xVals[i].begin(),xVals[i].end());
            ll curSum=0;
            for(pair<ll,ll> j : xVals[i]){
                curSum+=j.first-xVals[i][0].first;
            }
            fences[xVals[i][0].second].heightSum=curSum;
            for(ll j=1;j<xVals[i].size();j++){
                curSum+=(2*j-xVals[i].size())*(xVals[i][j].first-xVals[i][j-1].first);
                fences[xVals[i][j].second].heightSum=curSum;
            }
        }
    }

    for(ll i=0;i<=20000;i++){
        if(yVals[i].size()>0) {
            sort(yVals[i].begin(),yVals[i].end());
            ll curSum=0;
            for(pair<ll,ll> j : yVals[i]){
                curSum+=j.first-yVals[i][0].first;
            }
            fences[yVals[i][0].second].baseSum=curSum;

            for(ll j=1;j<yVals[i].size();j++){
                curSum+=(2*j-yVals[i].size())*(yVals[i][j].first-yVals[i][j-1].first);
                fences[yVals[i][j].second].baseSum=curSum;
            }
        }
    }

    ll ans=0;
    for(fence i : fences){
        ans+=((i.baseSum*i.heightSum) % 1000000007);
    }
    cout<<(ans % 1000000007);
    return 0;
}
