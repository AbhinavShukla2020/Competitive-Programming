#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int N,M;
    cin>>N>>M;
    vector<int> ATK,DEF;
    vector<int> ciel(M);

    for(int i=0;i<N;i++){
        string a;
        int b;
        cin>>a>>b;
        if(a=="ATK"){
            ATK.push_back(b);
        }else{
            DEF.push_back(b);
        }
    }
    sort(ATK.begin(),ATK.end());
    sort(DEF.begin(),DEF.end());

    for(int i=0;i<M;i++){
        cin>>ciel[i];
    }


    int ans=0;

    //Case 1:
    int curAns=0;
    bool works=true;
    multiset<int> cielCards;
    for(int i : ciel){
        cielCards.insert(i);
    }
    for(int a : DEF){
        if(cielCards.upper_bound(a)!=cielCards.end()){
            cielCards.erase(cielCards.upper_bound(a));
        }else{
            works=false;
            break;
        }
    }

    for(int b : ATK){
        if(cielCards.lower_bound(b)!=cielCards.end()){
            curAns+=abs(*cielCards.lower_bound(b)-b);
            cielCards.erase(cielCards.lower_bound(b));
        }else{
            works=false;
            break;
        }
    }
    for(int b : cielCards){
        curAns+=b;
    }
    if(works){
        ans=curAns;
    }


    //Case 2:
    sort(ATK.begin(),ATK.end());
    sort(ciel.begin(),ciel.end(),greater<int>());
    int sum1=0;
    int sum2=0;
    for(int i=0;i<ATK.size() && i<M;i++){
        if(ciel[i]>=ATK[i]){
            sum1+=ciel[i];
            sum2+=ATK[i];
        }
    }
    ans=max(ans,abs(sum2-sum1));

    cout<<ans<<endl;

    return 0;
}
