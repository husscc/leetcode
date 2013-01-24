/*
Implement pow(x, n).
*/
class Solution {
    double _pow(double x,int n){
		double a=_pow(x,n/2);
        if(n&0x1==1)
			return a*a*x;
		else
			return a*a;
	}
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!n||x==1)
            return 1;
        if(!x)
            return 0;
		
        if(n<0)
            x=1/x;
        n=abs(n);
		if(n==1)
			return x;
		
		double a=pow(x,n/2);
        if(n&0x1==1)
			return a*a*x;
		else
			return a*a;
    }
};