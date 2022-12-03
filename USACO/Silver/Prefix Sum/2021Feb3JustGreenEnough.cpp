#include <iostream>
#include <vector>
#include <map>
using namespace std;
long long N;
long long getBest(long long a,vector<vector<long long>> grid){
    vector<vector<long long>> psums;
    for(long long c=0;c<N;c++){
        vector<long long> curPsum;
        curPsum.push_back(0);
        for(long long r=1;r<=N;r++){
            curPsum.push_back(curPsum[r-1]+((grid[r-1][c]<a) ? 1 : 0));
        }
        psums.push_back(curPsum);
    }

    long long ans=0;
    for(long long i=1;i<=N;i++){
        for(long long j=i;j<=N;j++){
            long long curRun=0;
            for(long long k=0;k<N;k++){
                if(psums[k][j]-psums[k][i-1]==0){
                    curRun++;
                    ans+=curRun;
                }else{
                    curRun=0;
                }
            }
        }
    }
    return ans;

}
int main() {
    cin>>N;
    vector<vector<long long>> grid(N);
    for(long long i=0;i<N;i++){
        grid[i].resize(N);
    }
    for(long long r=0;r<N;r++){
        for(long long c=0;c<N;c++){
            cin>>grid[r][c];
        }
    }
    cout<<getBest(100,grid)-getBest(101,grid);
    return 0;
}
