/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. 
If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). 
You are responsible to gather all the input requirements up front.
*/
class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	while(*str!='\0'&&*str==' ')
			str++;
		
		bool positive=true;
		if(*str=='-'){
			positive=false;
			str++;
		}
		else if(*str=='+')
			str++;
			
		int res=0;
		if(positive){
			int MAXINT_REMAIN=INT_MAX%10;
			int MAXDIVIDEDBYTEN=INT_MAX/10;
			while(isdigit(*str)){
				if(res>MAXDIVIDEDBYTEN||(res==MAXDIVIDEDBYTEN&&(*str-'0')>=MAXINT_REMAIN))
					return INT_MAX;
				res=res*10+*str-'0';
				str++;
			}
		}
		else{
			int MININT_REMAIN=INT_MIN%10;
			int MINDIVIDEDBYTEN=INT_MIN/10;
			while(isdigit(*str)){
				if(res<MINDIVIDEDBYTEN||(res==MINDIVIDEDBYTEN&&('0'-*str)<=MININT_REMAIN))
					return INT_MIN;
				res=res*10-(*str-'0');
				str++;
			}
		}
		
		return res;
    }
};