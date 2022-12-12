#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
int main() {
    int N;
    cin>>N;
    vector<int> nums(N);
    vector<int> numToPlace(N+1);
    for(int i=0;i<N;i++){
        cin>>nums[i];
        numToPlace[nums[i]]=i;
    }
//SOLUTION 1
    set<int> index;
    long long ans=0;
    for(int i=N;i>=1;i--){
        auto it=index.insert(numToPlace[i]).first;
        if(next(it)!=index.end()){
            ans+=*next(it)-*it+1;
        }

    }
    reverse(nums.begin(),nums.end());
    for(int i=0;i<N;i++){
        numToPlace[nums[i]]=i;
    }
    index.clear();
    for(int i=N;i>=1;i--){
        auto it=index.insert(numToPlace[i]).first;
        if(next(it)!=index.end()){
            ans+=*next(it)-*it+1;
        }

    }
    cout<<ans;


//SOLUTION 2
//    long long ans=0;
//    stack<int> cur;
//    for(int i=N-1;i>=0;i--){
//        while (!cur.empty() && nums[cur.top()] < nums[i]) { cur.pop(); }
//        if(!cur.empty()){
//            ans += cur.top() - i + 1;
//        }
//        cur.push(i);
//    }
//
//    reverse(nums.begin(),nums.end());
//
//    stack<int> cur2;
//    for(int i=N-1;i>=0;i--){
//        while (!cur2.empty() && nums[cur2.top()] < nums[i]) { cur2.pop(); }
//        if(!cur2.empty()){
//            ans += cur2.top() - i + 1;
//        }
//        cur2.push(i);
//    }
//    cout<<ans;
    return 0;
}
