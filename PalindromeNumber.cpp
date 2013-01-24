/*
Determine whether an integer is a palindrome. Do this without extra space.
*/
class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(x<0)
            return false;
		else if(x<10)
			return true;
			
		int x_divisor=0,x_mirror=x;

		while(x_mirror>9){
			x_divisor++;
			x_mirror/=10;
		}
		
		x_divisor=pow(10,x_divisor);
		
		while(x>9){
			int high=x/x_divisor,low=x%10;
			if(high!=low)
				return false;
            x=x-x_divisor*high;
            x/=10;
			x_divisor/=100;
		}
		
		return true;
    }
};