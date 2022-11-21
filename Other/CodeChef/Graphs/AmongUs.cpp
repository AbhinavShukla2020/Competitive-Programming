#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main() {
    long long T;
    cin>>T;
    for(long long t=0;t<T;t++) {
        bool finalWorks = true;
        long long N, M;
        cin >> N >> M;
        if(M==0){
            cout<<N<<endl;
            continue;
        }
        vector<vector<long long>> adj(N + 1);
        map<pair<long long, long long>, long long> type;
        for (long long i = 0; i < M; i++) {
            long long a, b, c;
            cin >> a >> b >> c;
            adj[b].push_back(c);
            adj[c].push_back(b);
            if (type.find({b, c}) != type.end()) {
                if (type[{b, c}] != a) {
                    finalWorks = false;
                }
            }else {
                type[{b, c}] = a;
                type[{c, b}] = a;
            }
        }



        bool vis[N+1];
        for(int i=0;i<=N;i++){
            vis[i]=false;
        }


        long long group[N+1];
        long long ans=0;
      
        for(long long z=1;z<=N;z++){
            if(!finalWorks){
                break;
            }
            if(vis[z]==false){
                int imposters=0;
                int crewmates=0;
                imposters++;
                group[z]=0;
                stack<long long> dfs;
                dfs.push(z);
                vis[z]=true;
                while(!dfs.empty()){
                    long long k=dfs.top();
                    dfs.pop();
                    for(long long i : adj[k]){
                        if(vis[i]==false){
                            dfs.push(i);
                            vis[i]=true;
                            if(type[{k,i}]==1){
                                group[i]=((group[k]+1) % 2);
                            }else{
                                group[i]=group[k];
                            }
                            if(group[i]==0){
                                imposters++;
                            }else if(group[i]==1){
                                crewmates++;
                            }
                        }else{
                            if(type[{k,i}]==1 && group[i]==group[k]){
                                finalWorks=false;
                            }else if(type[{i,k}]==2 && group[i]!=group[k]){
                                finalWorks=false;
                            }
                        }
                    }

                }

                ans+=max(imposters,crewmates);
            }
        }

        if(finalWorks){
            cout<<ans<<endl;
        }else{
            cout<<-1<<endl;
        }
    }
    return 0;
}
