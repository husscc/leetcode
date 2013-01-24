/*
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
*/
class Solution {
    int boardsize;
	void nextSlot(int x,int y,char* available,int remain,int &res){
		if(remain>boardsize-x)
			return;
		
		int next_x=x,next_y=y+1;
		if(next_y==boardsize){
			next_x++;
			next_y=0;
		}
		
		if(available[x*boardsize+y]){
			if(remain>1){
				char* available_mirror=new char[boardsize*boardsize];
				memcpy(available_mirror,available,boardsize*boardsize*sizeof(char));
				
				for(int i=0;i<boardsize;i++){
					available_mirror[i*boardsize+y]=0x0;
					available_mirror[x*boardsize+i]=0x0;
				}
				for(int i=x-1,j=y-1;i>=0&&j>=0;i--,j--)
					available_mirror[i*boardsize+j]=0x0;
				
				for(int i=x+1,j=y+1;i<boardsize&&j<boardsize;i++,j++)
					available_mirror[i*boardsize+j]=0x0;
					
				for(int i=x-1,j=y+1;i>=0&&j<boardsize;i--,j++)
					available_mirror[i*boardsize+j]=0x0;
					
				for(int i=x+1,j=y-1;i<boardsize&&j>=0;i++,j--)
					available_mirror[i*boardsize+j]=0x0;
				
				nextSlot(x+1,0,available_mirror,remain-1,res);
				
				delete []available_mirror;
			}
			else
				res++;
		}
		
		nextSlot(next_x,next_y,available,remain,res);
	}
public:
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(n==0)
			return 0;
		if(n==1)
			return 1;
			
		char *available=new char[n*n];
		memset(available,0x1,sizeof(char)*n*n);

		boardsize=n;
		int res=0;
		
		nextSlot(0,0,available,n,res);
		delete []available;
		return res;
    }
};