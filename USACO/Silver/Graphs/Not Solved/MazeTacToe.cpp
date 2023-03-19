#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>
#include <array>
#include <algorithm>
#include <cassert>
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

int N;
bool vis[25][25][19685];
int grid[25][25]; //0 for empty, 1 M, 2 0 , 3 Wall
map<pii,array<int,3>> blocks; //0 empty, 1 M , 2 O
pair<int,int> bessie;
int pow3[10]={1,3,9,27,81,243,729,2187,6561,19683};
set<int> ans;
bool test_win(int b)
{
  int cells[3][3];
  for (int i=0; i<3; i++)
    for (int j=0; j<3; j++) {
      cells[i][j] = b%3;
      b /= 3;
    }
  for (int r=0; r<3; r++) {
    if (cells[r][0] == 1 && cells[r][1] == 2 && cells[r][2] == 2) return true;
    if (cells[r][0] == 2 && cells[r][1] == 2 && cells[r][2] == 1) return true;
  }
  for (int c=0; c<3; c++) {
    if (cells[0][c] == 1 && cells[1][c] == 2 && cells[2][c] == 2) return true;
    if (cells[0][c] == 2 && cells[1][c] == 2 && cells[2][c] == 1) return true;
  }
  if (cells[0][0] == 1 && cells[1][1] == 2 && cells[2][2] == 2) return true;
  if (cells[0][0] == 2 && cells[1][1] == 2 && cells[2][2] == 1) return true;
  if (cells[2][0] == 1 && cells[1][1] == 2 && cells[0][2] == 2) return true;
  if (cells[2][0] == 2 && cells[1][1] == 2 && cells[0][2] == 1) return true;
  return false;
}
 

void floodfill(int r,int c,int state){
	if ((r < 0 || r >= N || c < 0 || c >= N)  // if out of bounds
	    || grid[r][c]==3                          // wrong color
	    || vis[r][c][state]  // already visited this square
	)
		return;
	// cout<<r<<" "<<c<<endl;
	// return;

	vis[r][c][state] = true;  // mark current square as visited
	
	if(grid[r][c]==1 || grid[r][c]==2){
		int r2=blocks[{r,c}][1],c2=blocks[{r,c}][2];
		int index=3*r2+c2;
      //  cout<<index<<"    "<<pow3[index]<<endl;
		int current=(state/pow3[index]);
		current%=3;
       // int current=0;
		if(current==0){
			int new_char=grid[r][c];
			state=(state % pow3[index])+new_char*pow3[index]+(state-state%pow3[index+1]);
			if(test_win(state)){ans.insert(state); return;}
			//vis[r][c][state]=true;
		}
	}

	// recursively call flood fill for neighboring squares
	floodfill(r, c + 1, state);
	floodfill(r, c - 1, state);
	floodfill(r - 1, c, state);
	floodfill(r + 1, c, state);
}


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>N;
	FOR0(r,N){
		string in;
		cin>>in;
		for(int c=0;c<3*N;c+=3){
			if(in.at(c)=='#'){
				grid[r][c/3]=3;
			}else if(in.at(c)=='.'){
				grid[r][c/3]=0;
			}else if(in.at(c)=='M'){
				grid[r][c/3]=1;
                                
				blocks[{r,c/3}]={1,in.at(c+1)-'0'-1,in.at(c+2)-'0'-1};
			}else if(in.at(c)=='O'){
				grid[r][c/3]=2;
				blocks[{r,c/3}]={2,in.at(c+1)-'0'-1,in.at(c+2)-'0'-1};
			}else{
			//	cout<<"found bessie"<<endl;
				bessie={r,c/3};
			}	
		}
	}
        // TRAV(i,blocks){
        //        cout<<i.first.first<<" "<<i.first.second<<" "<<i.second[0]<<" "<<i.second[1]<<" "<<i.second[2]<<endl;
        // }
       // return 0;
	//cout<<"done reading"<<endl;
	// return 0;
	floodfill(bessie.first,bessie.second,0);

	cout<<ans.size()<<endl;



	return 0;
}
