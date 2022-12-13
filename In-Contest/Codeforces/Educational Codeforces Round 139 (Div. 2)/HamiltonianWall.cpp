#include <iostream>
#include <vector>
using namespace std;
int main() {
    int T;
    cin>>T;
    for(int k=0;k<T;k++){
        //cout<<endl<<endl;
        int N;
        cin>>N;
        int start=0;
        vector<pair<char,char>> grid(N);
        for(int i=0;i<N;i++){
            cin>>grid[i].first;
        }
        for(int i=0;i<N;i++){
            cin>>grid[i].second;
        }
        bool metBB=false;
        bool works=true;
        for(pair<int,int> i : grid){
            if((i.first=='B' && i.second=='W') || (i.first=='W' && i.second=='B')){
                break;
            }
            if(metBB==true && (i.first=='W' && i.second=='W')){
                works=false;
                break;
            }
            if(i.first=='B' && i.second=='B'){
                metBB=true;
            }
            start++;
        }
        int actLast=N-1;
        for(int i=0;i<N;i++){
            if(grid[i]==make_pair('W','W')){
                actLast=i;
                break;
            }

        }
      //  cout<<actLast<<endl;
        if(!works){
            cout<<"NO"<<endl;
            continue;
        }
        if(start==N){
            cout<<"YES"<<endl;
            continue;
        }
        int curRowNum=0;
        if(grid[start].second=='B'){
            curRowNum=1;
        }
        int last=-1;
        for(int i=start+1;i<N;i++){
          //  cout<<i<<" "<<curRowNum<<endl;
            if(grid[i]==make_pair('B','B')){
                curRowNum++;
                curRowNum=curRowNum%2;
                continue;
            }
            if(grid[i]==make_pair('W','W')){
                last=i;
                break;
            }
            if(curRowNum==0){
                if(grid[i].first!='B'){
                    works=false;
                    last=i;
                    break;
                }
            }
            if(curRowNum==1){
                if(grid[i].second!='B'){
                    works=false;
                    last=i;
                    break;
                }
            }

        }
//        cout<<"start "<<start<<endl;
//        cout<<"last "<<last<<endl;
        if(!works || (last!=-1 && last!=actLast)){
            cout<<"NO"<<endl;
        }else {
            cout << "YES" << endl;
        }
    }
    return 0;
}
