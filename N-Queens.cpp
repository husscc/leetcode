/*
The n-queens puzzle is the problem of placing n queens on an n¡Án chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, 
where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/
class Solution {
    int boardSize;
	
	void nextSlot(int x,int y,int remain,vector<string> cur,vector<vector<string> > &res){
		if(remain>boardSize-x)
			return;
		
		bool canPlace=true;
		for(int i=0;canPlace&&i<y;i++){								//check horizontal
			if(cur[x][i]=='Q')
				canPlace=false;
		}
		for(int i=0;canPlace&&i<x;i++){								//check vertical
			if(cur[i][y]=='Q')
				canPlace=false;
		}
		for(int i=x-1,j=y-1;canPlace&&i>=0&&j>=0;i--,j--){			//check diagonal
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
			else
				nextSlot(x+1,0,remain-1,tmp,res);
		}
			
		int next_x=x,next_y=y+1;
		if(next_y>=boardSize){
			next_x++;
			next_y=0;
		}
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