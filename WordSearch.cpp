/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
(No Return Route)
*/

class Solution {
    struct location{
        int _x;
		int _y;
		int _step;
		int direction;
		location(int x,int y,int step):_x(x),_y(y),_step(step),direction(4){}
	};

public:
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int slen=word.size(),xlen=board.size(),ylen,x_axis,y_axis,step=0;
		if(!slen)
			return true;
		
		if(xlen>0)
			ylen=board[0].size();
		
		stack<location> s;
		vector<vector<unsigned char> > used(xlen,vector<unsigned char>(ylen,0x0));
		
		for(int i=0;i<xlen;i++){
			for(int j=0;j<ylen;j++){
				if(word[0]==board[i][j]){
					if(slen==1)
						return true;
					s.push(location(i,j,0));
					used[i][j]=0x1;
					
					while(s.size()>0){
						x_axis=s.top()._x;
						y_axis=s.top()._y;
						step=s.top()._step;
						switch(s.top().direction){
							case 4:
								s.top().direction--;
								if((x_axis-1)>=0&&(!used[x_axis-1][y_axis])&&board[x_axis-1][y_axis]==word[step+1]){
									if(step+1==slen-1)
										return true;
									used[x_axis-1][y_axis]=0x1;
									s.push(location(x_axis-1,y_axis,step+1));
								}
								break;
							case 3:
								s.top().direction--;
								if((x_axis+1)<xlen&&(!used[x_axis+1][y_axis])&&board[x_axis+1][y_axis]==word[step+1]){
									if(step+1==slen-1)
										return true;
									used[x_axis+1][y_axis]=0x1;
									s.push(location(x_axis+1,y_axis,step+1));
								}
								break;
							case 2:
								s.top().direction--;
								if((y_axis-1)>=0&&(!used[x_axis][y_axis-1])&&board[x_axis][y_axis-1]==word[step+1]){
									if(step+1==slen-1)
										return true;
									used[x_axis][y_axis-1]=0x1;
									s.push(location(x_axis,y_axis-1,step+1));
								}
								break;
							case 1:
								s.top().direction--;
								if((y_axis+1)<ylen&&(!used[x_axis][y_axis+1])&&board[x_axis][y_axis+1]==word[step+1]){
									if(step+1==slen-1)
										return true;
									used[x_axis][y_axis+1]=0x1;
									s.push(location(x_axis,y_axis+1,step+1));
								}
								break;
							default:
								used[x_axis][y_axis]=0x0;
								s.pop();
						}
					}
				}
			}
		}
		return false;
    }
};