#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;

using ll = long long;
using pii = pair<ll,ll>;


int main(){
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);
	string in;
	int N;
	cin>>in;
	cin>>N;
	vector<int> psumC(N+1,0);
	vector<int> psumO(N+1,0);
	vector<int> psumW(N+1,0);
	int counter=1;
	for(char i : in){
		psumC[counter]=psumC[counter-1];
		psumO[counter]=psumO[counter-1];
		psumW[counter]=psumW[counter-1];

		if(i=='C'){
			psumC[counter]+=1;
		}else if(i=='O'){
			psumO[counter]+=1;
		}else{
			psumW[counter]+=1;
		}
		counter++;
	}

	for(int i=0;i<N;i++){
		int a,b;
		cin>>a>>b;
		int cCount=psumC[b]-psumC[a-1];
		int oCount=psumO[b]-psumO[a-1];
		int wCount=psumW[b]-psumW[a-1];
		//cout<<cCount<<" "<<oCount<<" "<<wCount<<endl;
		if((oCount + wCount)%2==0 && (cCount+wCount)%2==1){
			cout<<"Y";
		}else{
			cout<<"N";
		}
	}

}