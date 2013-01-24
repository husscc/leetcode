#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <stack>
#include <assert.h>
#include <algorithm>
//#include <ext/hash_map>
using namespace std;
//using namespace __gnu_cxx;


class Solution {
    int boardSize;
	
	void nextSlot(int x,int y,int remain,vector<string> cur,vector<vector<string> > &res){
		if(remain>boardSize-x)
			return;
		
		bool canPlace=true;
		for(int i=0;canPlace&&i<y;i++){
			if(cur[x][i]=='Q')
				canPlace=false;
		}
		for(int i=0;canPlace&&i<x;i++){
			if(cur[i][y]=='Q')
				canPlace=false;
		}
		for(int i=x-1,j=y-1;canPlace&&i>=0&&j>=0;i--,j--){
			if(cur[i][j]=='Q')
				canPlace=false;
		}
		for(int i=x-1,j=y+1;canPlace&&i>=0&&j<boardSize;i--,j++){
			if(cur[i][j]=='Q')
				canPlace=false;			
		}
		
		vector<string> tmp;
		if(canPlace){
			tmp=cur;
			tmp[x][y]='Q';
			
			if(remain==1)
				res.push_back(tmp);
		}
		
		if((x==boardSize-1)&&(y==boardSize-1))
			return;
			
		int next_x,next_y;
		if(y+1>=boardSize){
			next_x=x+1;
			next_y=0;
		}
		else{
			next_x=x;
			next_y=y+1;
		}
			
		if(canPlace&&remain>1)
			nextSlot(next_x,next_y,remain-1,tmp,res);

		nextSlot(next_x,next_y,remain,cur,res);
	}
	
public:
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string> > res;
		if(n<1)
			return res;
		
		boardSize=n;
		vector<string> cur;
		string str="";
		for(int i=0;i<boardSize;i++)
			str+='.';
		for(int i=0;i<boardSize;i++)
			cur.push_back(str);
		
		nextSlot(0,0,n,cur,res);
		
		return res;
    }
};

int main(){
	Solution s;
	vector<vector<string> > res;
	res=s.solveNQueens(8);
	
	cout<<res.size()<<endl;
	for(int i=0;i<8;i++){
		cout<<res[res.size()-1][i]<<endl;	
	}
}
