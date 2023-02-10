#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <unordered_set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>
 
using namespace std;
 
using pii = pair<int,int>;
using vi = vector<int>;

#define endl "\n"
#define int int64_t 
#define pb push_back
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR0(i,a) FOR(i,0,a)
#define FOR1(i,a) for (int i = (1); i <= (a); ++i)
#define TRAV(a,x) for (auto& a: x)

const int MAXN=1e5+5;
map<char,set<char>> adjDirect;
map<char,set<char>> adjUnDirect;
map<char,bool> vis;
int N;
bool cycle=false;
vector<char> sizeUnDirect(char a){
	vector<char> ans;
	//ans.pb(a);
	queue<char> cur;
	cur.push(a);
	vis[a]=true;
	while(!cur.empty()){
		char curNode=cur.front();
		cur.pop();
		ans.pb(curNode);
		TRAV(i,adjUnDirect[curNode]){
			if(!vis[i]){
				cur.push(i);
				vis[i]=true;
			}
		}
	}
	return ans;
}
int sizeDirect(int a){
	vector<char> ans;
	set<char> vis2;
	//ans.pb(a);
	vis2.insert(a);
	queue<int> cur;
	cur.push(a);
	while(!cur.empty()){
		char curNode=cur.front();
		cur.pop();
		ans.pb(curNode);
		TRAV(i,adjDirect[curNode]){
			if(vis2.find(i)==vis2.end()){
				cur.push(i);
				vis2.insert(i);
			}else{
				cycle=true;
			}
		}
	}
	return ans.size();
}
int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--){
		adjDirect.clear();
		adjUnDirect.clear();
		vis.clear();
		string a,b;
		set<char> nodes;
		set<char> node2;
		cin>>a>>b;
		N=a.size();
		map<char,set<char>> adjDirect2;
		FOR0(i,a.size()){
			nodes.insert(a.at(i));
			nodes.insert(b.at(i));
			node2.insert(b.at(i));
			vis[a.at(i)]=false;
			vis[b.at(i)]=false;
			adjDirect2[a.at(i)].insert(b.at(i));
			if(a.at(i)!=b.at(i)){
				adjDirect[a.at(i)].insert(b.at(i));
			}
			adjUnDirect[a.at(i)].insert(b.at(i));
			adjUnDirect[b.at(i)].insert(a.at(i));
		}
		bool works=true;
		if(a!=b && node2.size()==52){
			works=false;
		}
		
		TRAV(i,adjDirect2){
			if(i.second.size()>1){
				works=false;
				break;
			}
		}
		if(!works){
			cout<<-1<<endl;
			continue;
		}
		int ans=0;
		TRAV(i,nodes){
			if(!vis[i]){
				cycle=false;
				//cout<<endl<<i<<endl;
				vector<char> cur=sizeUnDirect(i);
				// TRAV(j,cur){
				// 	cout<<j<<" ";
				// }
				//cout<<endl;
				bool cycle1=true;
				//bool cycle2=false;
				TRAV(j,cur){
					if(sizeDirect(j)!=cur.size()){
						//cout<<j<<" "<<cur.size()<<" "<<sizeDirect(j)<<endl;
						cycle1=false;
					//	break;
					}
				}
				if(cur.size()==1){
					continue;
				}
				if(cycle1){
				//	cout<<"cycle"<<endl;
					if(cur.size()>=52){
						works=false;
						break;
					}
					ans+=cur.size()+1;
				}else if(cycle){
					ans+=cur.size();
				}else{
					ans+=cur.size()-1;
				}
			}
		}
		if(!works){
			cout<<-1<<endl;
			continue;
		}
		cout<<ans<<endl;
	}


	return 0;
}
