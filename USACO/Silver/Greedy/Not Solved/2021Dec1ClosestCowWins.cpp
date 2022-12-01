#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;
int main() {
    ll K,M,N;
    cin>>K>>M>>N;
    vector<pair<ll,ll>> grass(K);
    //Cal Farmer Nhoj's cows evil
    vector<ll> evil(M);
    for(ll i=0;i<K;i++){
        cin>>grass[i].first>>grass[i].second;
    }
    for(ll i=0;i<M;i++){
        cin>>evil[i];
    }
    sort(grass.begin(),grass.end());
    sort(evil.begin(),evil.end());

    //Vector to store best sum on each interval
    vector<ll> bestSums;
    ll firstSum=0;
    ll lastSum=0;
    ll pointer1=0;
    ll pointer2=0;
    ll l=0,r=0;

    //Consider first and last interval separately because they only have 1 endpoint
    for(pair<ll,ll> i : grass){
        if(i.first<evil[0]){
            pointer2++;
            firstSum+=i.second;
            l++;
            r++;
        }else if(i.first>evil[M-1]){
            lastSum+=i.second;
        }
    }
    bestSums.push_back(firstSum);
    bestSums.push_back(lastSum);

    //Pre-compute totalSums in each interval using 2 pointer method
    vector<ll> totSums;
    while(pointer1<M-1 && pointer2<K){
        ll curSum=0;
        while(pointer2<K && grass[pointer2].first<evil[pointer1+1]){
            curSum+=grass[pointer2].second;
            pointer2++;
        }
        pointer1++;
        totSums.push_back(curSum);
    }

    //Use 2-pointer method on all intervals to find best interval
    for(ll i=0;i<M-1;i++){
        ll length=evil[i+1]-evil[i];
        ll curSum=0;
        ll bestSum=0;
        while(grass[l].first<evil[i+1] && grass[r].first<evil[i+1]) {
            while (grass[r].first<evil[i+1] && (2 * (grass[r].first - grass[l].first)) < length) {
                curSum+=grass[r].second;
                r++;
            }
            bestSum=max(curSum,bestSum);
            curSum-=grass[l].second;
            l++;
        }
        bestSums.push_back(bestSum);
        bestSums.push_back(totSums[i]-bestSum);
        l=r;
    }

    //Compute answer
    sort(bestSums.begin(),bestSums.end(),greater<ll>());
    ll ans=0;
    for(ll i=0;i<N && i<bestSums.size();i++){
        ans+=bestSums[i];
    }
    cout<<ans<<endl;
    return 0;
}
