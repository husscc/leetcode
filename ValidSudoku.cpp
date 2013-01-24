/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	
		bool check9[9];
		
		//check line
		for(int i=0;i<9;i++){
			memset(check9,0,sizeof(check9));
			for(int j=0;j<9;j++){
				if(board[i][j]=='.')
					continue;
				if(check9[(int)(board[i][j]-'1')])
					return false;
				else
					check9[(int)(board[i][j]-'1')]=true;
			}
		}
		
		//check row
		for(int i=0;i<9;i++){
			memset(check9,0,sizeof(check9));
			for(int j=0;j<9;j++){
				if(board[j][i]=='.')
					continue;
				if(check9[(int)(board[j][i]-'1')])
					return false;
				else
					check9[(int)(board[j][i]-'1')]=true;
			}
		}
		
		//check submatrix
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				memset(check9,0,sizeof(check9));
				for(int k=3*i;k<3*i+3;k++){
					for(int l=3*j;l<3*j+3;l++){
						if(board[k][l]=='.')
							continue;
						if(check9[(int)(board[k][l]-'1')])
							return false;
						else
							check9[(int)(board[k][l]-'1')]=true;
					}
				}
			}
		}	
		return true;
    }
};