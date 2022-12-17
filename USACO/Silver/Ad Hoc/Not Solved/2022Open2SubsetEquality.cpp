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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string in1,in2;
	cin>>in1>>in2;
	vector<char> letters = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r'};
	bool works[18][18];

	for(int i=0;i<18;i++){
		for(int j=i;j<18;j++){

			string cur1,cur2;
			for(char u : in1){
				if(u==letters[i] || u==letters[j]){
					cur1.push_back(u);
				}
			}
			for(char u : in2){
				if(u==letters[i] || u==letters[j]){
					cur2.push_back(u);
				}
			}
			if(cur1==cur2){
				works[i][j]=true;
				works[j][i]=true;
			}else{
				works[i][j]=false;
				works[j][i]=false;
			}
		}
	}

	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		string a;
		cin>>a;
		bool curWorks=true;
		for(char x : a){
			for(char y : a){
				if(!works[x-'a'][y-'a']){
					curWorks=false;
				}
			}
		}
		if(curWorks){
			cout<<"Y";
		}else{
			cout<<"N";
		}
	}

	return 0;
}