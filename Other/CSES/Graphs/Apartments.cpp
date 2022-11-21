#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int N,M,K;
    cin>>N>>M>>K;
    vector<int> customers;
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        a-=K;
        customers.push_back(a);
    }
    sort(customers.begin(),customers.end());
    vector<int> apartments;
    for(int i=0;i<M;i++){
        int a;
        cin>>a;
        apartments.push_back(a);
    }
    sort(apartments.begin(),apartments.end());
    int pointer1,pointer2;
    pointer1=0;
    pointer2=0;
    int ans=0;
    while(pointer1<N && pointer2<M){
   //     cout<<pointer1<<" "<<pointer2<<endl;
        if(apartments[pointer2]>customers[pointer1]+2*K){
            pointer1++;
        }else if(customers[pointer1]<=apartments[pointer2] && customers[pointer1]+2*K>=apartments[pointer2]){
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
