/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n<=0)
			return 0;
		if(n==1)
			return 1;
		if(n==2)
			return 2;
		
		int i,i_1=2,i_2=1;	//start from i=3
		for(int j=3;j<n+1;j++){
			i=i_1+i_2;
			i_2=i_1;
			i_1=i;
		}
		
		return i;
    }
};