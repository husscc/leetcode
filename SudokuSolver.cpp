/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.
*/
class Solution {

    inline bool checkRow(int row,char target,vector<vector<char> > &board){
        for(int i=0;i<9;i++){
    		if(board[row][i]==target)
				return false;
		}
		return true;
	}

	inline bool checkColumn(int column,char target,vector<vector<char> > &board){
		for(int i=0;i<9;i++){
			if(board[i][column]==target)
				return false;
		}
		return true;
	}

	inline bool checkSubMatrix(int row,int column,char target,vector<vector<char> > &board){
		row=(row/3)*3;
		column=(column/3)*3;		
		for(int i=row+2;i>=row;i--){
			for(int j=column+2;j>=column;j--){
				if(board[i][j]==target)
					return false;
			}
		}
		return true;
	}
    
	
	bool generateSudoku(int x,int y,vector<vector<char> > &board){
		if(x>8)
			return true;
		
		int _x,_y;
		if(y==8) {_x=x+1;_y=0;}
		else {_x=x;_y=y+1;}

		if(board[x][y]!='.'){
			if(generateSudoku(_x,_y,board))
                return true;
            else
                return false;
		}
		else{
			for(char i='1';i<='9';i++){
				if(checkRow(x,i,board)&&checkColumn(y,i,board)&&checkSubMatrix(x,y,i,board)){
                    board[x][y]=i;
					if(generateSudoku(_x,_y,board))
						return true;
				}
                
			}
			board[x][y]='.';
            return false;
		}
	}

public:
    void solveSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        generateSudoku(0,0,board);
		return;
    }
};