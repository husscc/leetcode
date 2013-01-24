/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/
class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!x)
            return x;
        
        int symbol=1,res=0;
        
        if(x<0){
            symbol=-1;
            x=~x+1;
        }
        
        while(x){
            res=res*10+x%10;
            x/=10;
        }
        
        if(symbol==-1)
            res=~res+1;
        
        return res;
    }
};