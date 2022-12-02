#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
long long main() {
    long long K,N; cin>>K>>N;
    vector<pair<long long,long long>> movies(K);
    for(long long i=0;i<K;i++){
        cin>>movies[i].second>>movies[i].first;
    }
    sort(movies.begin(),movies.end());
    multiset<long long> endTimes;
    for(long long i=0;i<K;i++){
        swap(movies[i].first,movies[i].second);
    }
    long long ans=0;
    for(long long i=0;i<K;i++){
        if(endTimes.size()<N){
            ans++;
            endTimes.insert(movies[i].second);
        }else{
            auto it=endTimes.upper_bound(movies[i].first);
            if(it!=endTimes.begin()){
                it--;
                endTimes.erase(it);
                endTimes.insert(movies[i].second);
                ans++;
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}
