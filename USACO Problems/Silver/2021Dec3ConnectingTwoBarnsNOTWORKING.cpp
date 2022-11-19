//NOTE: THIS DOES NOT WORK
#include <vector>
#include <map>
#include <iostream>
#include <set>
#include <math.h>
#include <algorithm>
#include <stack>
using namespace std;
map<int,int> nodeToGroup;
//void printStack(stack<int> hi){
//    stack<int> hi2=hi;
//    while(hi2.empty()==false){
//        cout<<hi2.top()<<" ";
//        hi2.pop();
//    }
//    cout<<endl;
//}
pair<map<int,vector<int>>,map<int,int>> getConnectedComponent(vector<vector<int>> adj){
    map<int,bool> vis;

    int N=adj.size()-1;
    for(int i =1;i<=N;i++){
        vis[i]=false;
    }
    map<int,vector<int>> component;
    map<int,int> nodeToComp;
    int curColor=1;
    for(int a=1;a<=N;a++){
        if(vis[a]==false){
            //cout<<"hi"<<endl;
            stack<int> dfs;
            dfs.push(a);
            while(!dfs.empty()){
            //    printStack(dfs);
                int k=dfs.top();
                dfs.pop();
                vis[k]=true;
                component[curColor].push_back(k);
                nodeToComp[k]=curColor;
                for(int i : adj[i]){
                    if(vis[i]==false){
                        dfs.push(i);
                        vis[k]=true;
                    }
                }

            }
            curColor++;
        }

    }
//    for(pair<int,vector<int>> i : component){
//        cout<<i.first<<" : ";
//        for(int h : i.second){
//            cout<<h<<" ";
//        }
//        cout<<endl;
//    }
//    cout<<endl;
//    for(pair<int,int> i : nodeToComp){
//        cout<<"("<<i.first<<","<<i.second<<")"<<" ";
//    }
//    cout<<endl;
    return {component,nodeToComp};


}

int getSmallestDifference(vector<int> one, vector<int> two){
//    sort(one.begin(),one.end());
//    sort(two.begin(),two.end());
    int pointer1=0;
    int pointer2=0;
    int curBestDif=abs(one[0]-two[0]);
    while(pointer1<one.size() && pointer2<two.size()){
        //cout<<curBestDif<<endl;
        curBestDif=min(abs(one[pointer1]-two[pointer2]),curBestDif);
        if(pointer1==one.size()-1){
            pointer2++;
        }else if(pointer2==two.size()-1){
            pointer1++;
        }else {
            if (two[pointer2] >= one[pointer1]) {
                pointer1++;
            } else {
                pointer2++;
            }
        }
    }
    //cout<<curBestDif<<endl;
    return curBestDif;
}
int getSmallestDifference2(int in,vector<int> one, vector<int> two){
//    sort(one.begin(),one.end());
//    sort(two.begin(),two.end());
    int pointer1=0;
    int pointer2=0;
    int curBestDif=abs(one[0]-two[0]);
    while(pointer1<one.size() && pointer2<two.size()){
        //cout<<curBestDif<<endl;
        curBestDif=min(abs(one[pointer1]-two[pointer2]),curBestDif);
        if(pointer1==one.size()-1){
            pointer2++;
        }else if(pointer2==two.size()-1){
            pointer1++;
        }else {
            if (two[pointer2] >= one[pointer1]) {
                pointer1++;
            } else {
                pointer2++;
            }
        }
    }
    //cout<<curBestDif<<endl;
    return curBestDif;
}
int main(){
    //cout<<getSmallestDifference({1,10},{5,12,54,1,7});
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        int N,M;
        cin>>N>>M;
        vector<vector<int>> adj(N+1);
        bool vis[N+1];
        for(int i=0;i<M;i++){
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        pair<map<int,vector<int>>,map<int,int>> ayo=getConnectedComponent(adj);
        map<int,vector<int>> components= ayo.first;
        for(pair<int,vector<int>> i : components){
            cout<<i.first<<" : ";
            for(int h : i.second){
                cout<<h<<" ";
            }
            cout<<endl;
        }
        map<int,int> colors=ayo.second;
        vector<int> first=components[colors[1]];
        vector<int> last=components[colors[N]];

        //case 1:
        int firstAns= pow(getSmallestDifference(first,last),2);
        int ans=firstAns;
        //case 2:

        for(pair<int,vector<int>> i : components){
            if(colors[1]!=i.first && colors[N]!=i.first){
                int curAns=pow(getSmallestDifference(first,i.second),2)+pow(getSmallestDifference(i.second,last),2);
                ans=min(ans,curAns);
            }
        }

        cout<<ans<<endl;

    }
}
