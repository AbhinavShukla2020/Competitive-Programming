#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    long long T;
    cin>>T;
    for(long long k=0;k<T;k++) {
        long long N;
        cin >> N;
        vector<long long> nums;
        long long curMax=-1;
        long long curMin=10000001;
        for (long long i = 0; i < N; i++) {
            long long a;
            cin >> a;
            nums.push_back(a);
            curMax=max(curMax,a);
            curMin=min(curMin,a);
        }
        long long curMinCount=0;
        long long curMaxCount=0;
        for(int i=0;i<N;i++){
            if(nums[i]==curMin){
                curMinCount++;
            }
            if(nums[i]==curMax){
                curMaxCount++;
            }
        }
        if(curMin!=curMax) {
            long long curAns=2 * curMaxCount * curMinCount;
            cout << curAns << endl;
        }else{
            long long curAns=curMaxCount *(curMaxCount-1);
            cout<<curAns<<endl;
        }
    }
    return 0;
}
