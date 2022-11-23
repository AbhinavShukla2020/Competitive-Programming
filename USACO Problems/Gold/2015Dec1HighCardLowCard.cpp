#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
int main() {
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    int N;
    cin>>N;
    set<int> nums;
    vector<int> nums1;
    vector<int> nums2;
    for(int i=1;i<=2*N;i++){
        nums.insert(i);
    }
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        nums.erase(a);
        nums1.push_back(a);
    }
    for(int i : nums){
        nums2.push_back(i);
    }
    sort(nums2.begin(),nums2.end());

    vector<int> nums11;
    vector<int> nums12;
    vector<int> nums21;
    vector<int> nums22;
    for(int i=0;i<N/2;i++){
        nums11.push_back(nums1[i]);
    }
    for(int i=N/2;i<N;i++){
        nums12.push_back(nums1[i]);
    }for(int i=0;i<N/2;i++){
        nums21.push_back(nums2[i]);
    }
    for(int i=N/2;i<N;i++){
        nums22.push_back(nums2[i]);
    }
    sort(nums11.begin(),nums11.end());
    sort(nums12.begin(),nums12.end(),greater<int>());
    sort(nums21.begin(),nums21.end(),greater<int>());

    int pointer1=0;
    int pointer2=0;
    int ans=0;
    while(pointer1<N/2 && pointer2<N/2){
        if(nums22[pointer2]>nums11[pointer1]){
            ans++;
            pointer1++;
            pointer2++;
        }else{
            pointer2++;
        }
    }

    pointer1=0;
    pointer2=0;
    while(pointer1<N/2 && pointer2<N/2){
        if(nums21[pointer2]<nums12[pointer1]){
            ans++;
            pointer1++;
            pointer2++;
        }else{
            pointer2++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
