/*
Implement int sqrt(int x).

Compute and return the square root of x.
*/
class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        assert(x>=0);
    	if(x<1)
			return 0;
		
		double x1,x2=x;
		
		//use Newton Method
		//f(x)=x^2-n => f'(x)=2x
		//x2=x1-f(x1)/f'(x1) => x2=x1/2+n/(2x)
		do{	
			x1=x2;
			x2=x1/2+x/(2*x1);					
		}while(x1-x2!=0);					
		return x1;										
	}											
};