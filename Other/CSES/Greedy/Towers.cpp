#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <set>
using namespace std;
int main() {
    int N;
    cin>>N;
    vector<int> nums(N);
    for(int i=0;i<N;i++){
        cin>>nums[i];
    }

    multiset<int> towers;
    for(int i=0;i<N;i++){
        if(i==0){
            towers.insert(nums[i]);
            continue;
        }
        auto desired=towers.upper_bound(nums[i]);
        towers.insert(nums[i]);
        if(desired!=towers.end()){
            towers.erase(desired);
            continue;
        }
    }
    cout<<towers.size()<<endl;
    return 0;
}
