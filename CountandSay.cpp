/*

The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

*/
class Solution {
    
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //int index=0;
		int buffsize=pow(2,n-1)+1;
		char *pre,*cur,count;
		pre=(char*)malloc(sizeof(char)*buffsize);
		cur=(char*)malloc(sizeof(char)*buffsize);
		
		pre[0]='1';
		pre[1]='\0';
		int preidx,curidx;
		
		for(int i=1;i<n;i++){
			preidx=0;
			curidx=0;
			while(pre[preidx]!='\0'){
				
				count=1;
				while(pre[preidx]==pre[preidx+count]&&count<9)
					count++;
				cur[curidx]=(char)(count+'0');
				cur[curidx+1]=pre[preidx];
				preidx+=count;
				curidx+=2;
			}
			cur[curidx]='\0';
			
			cur=(char*)((unsigned int)pre^(unsigned int)cur);
    		pre=(char*)((unsigned int)pre^(unsigned int)cur);
			cur=(char*)((unsigned int)pre^(unsigned int)cur);
		}
		string res(pre);
        free(pre);
        free(cur);
		return res;
    }
};