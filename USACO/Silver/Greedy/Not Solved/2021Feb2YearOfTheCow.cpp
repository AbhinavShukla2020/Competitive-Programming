#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

map<int,int> groupToIndex;
int getLowest12(int a){
    return (a/12+1)*12;
}

int main() {
    int N,K;
    cin>>N>>K;
    vector<int> in(N);
    for(int i=0;i<N;i++) {
        cin >> in[i];
    }

    sort(in.begin(),in.end(),greater<int>());
    int curStart=getLowest12(in[0]);
    vector<int> groups;
    groups.push_back(0);
    groups.push_back(curStart);
    groupToIndex[curStart]=0;
    for(int i=1;i<N;i++){
        if(abs(in[i]-curStart)>12){
            curStart=getLowest12(in[i]);
            groups.push_back(curStart);
        }
    }

    int ans=12*(groups.size());
    sort(groups.begin(),groups.end());
    vector<int> getDifferences;
    for(int i=1;i<groups.size();i++){
        getDifferences.push_back(abs(groups[i]-groups[i-1]));
    }
    getDifferences.push_back(groups[groups.size()-1]-0);
    sort(getDifferences.begin(),getDifferences.end());

    for(int i=0;i<(getDifferences.size()-K);i++){
        ans+=(getDifferences[i]-12);
    }
    cout<<ans<<endl;
    return 0;
}
