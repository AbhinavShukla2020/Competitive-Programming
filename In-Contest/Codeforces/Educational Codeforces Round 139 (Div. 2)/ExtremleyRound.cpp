#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int main() {
    long long T;
    cin>>T;
    for(long long k=0;k<T;k++){
        long long in;
        cin>>in;
        long long ans=0;
        for(long long i=0;i<9;i++){
            for(long long j=1;j<=9;j++){
                if(j*pow(10,i)<=in){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
