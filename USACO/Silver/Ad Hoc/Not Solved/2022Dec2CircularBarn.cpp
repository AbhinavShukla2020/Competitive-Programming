#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;

const int MAXN=5e6+1;
using ll = long long;
using pii = pair<ll,ll>;
map<int,set<int>> primeMod4;
bool isPrime[MAXN+1];
void getPrimes(){
	for(int i=0;i<=MAXN;i++){
		isPrime[i]=true;
	}
	for(int i=2;i<sqrt(MAXN);i++){
		if(isPrime[i]){
			for(int j=i*i;j<=MAXN;j+=i){
				isPrime[j]=false;
			}
		}
	}
	for(int i=2;i<=MAXN;i++){
		if(isPrime[i]){
			primeMod4[(i%4)].insert(i);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	getPrimes();
	isPrime[1]=true;
	primeMod4[1].insert(1);
	int T;
	cin>>T;
	for(int t=0;t<T;t++){
		int N;
		cin>>N;
		bool winner[N+1];
		int amoMoves[N+1];
		for(int i=0;i<N;i++){
			amoMoves[i]=0;
			int cur;
			cin>>cur;
			if(cur%4==0){
				winner[i]=false;	
				amoMoves[i]=(cur/2);
			}else{
				winner[i]=true;
				auto it=(primeMod4[cur%4].upper_bound(cur));
				it--;
				int in2=cur;
				int greatestPrime=*it;
				cur-=greatestPrime;
				amoMoves[i]=1+(cur/2);
			}
			
		}

		int fastest=amoMoves[0];
		bool curWinner=winner[0];
		for(int i=0;i<N;i++){
			if(amoMoves[i]/2<fastest/2){
				curWinner=winner[i];
				fastest=amoMoves[i];
			}
		}
		if(curWinner){
			cout<<"Farmer John"<<endl;
		}else{
			cout<<"Farmer Nhoj"<<endl;
		}
	}

	return 0;
}
