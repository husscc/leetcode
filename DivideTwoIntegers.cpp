/*
Divide two integers without using multiplication, division and mod operator.
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        assert(divisor!=0);    
        
        long long dividend1,divisor1;
        dividend1=dividend;
        divisor1=divisor;

        if(dividend1==0)
    		return 0;
		else if(divisor1==1)
            return dividend1;
        else if(divisor1==-1)
            return 0-dividend1;
		
		int _sign=1;
		if(dividend1<0&&divisor1<0){
			dividend1=0-dividend1;
			divisor1=0-divisor1;
		}
		else if(dividend1<0&&divisor1>0){
			_sign=-1;
			dividend1=0-dividend1;
		}
		else if(dividend1>0&&divisor1<0){
    	    _sign=-1;
            divisor1=0-divisor1;
		}
        
		long long sftcount,cur,remain,res=0;
		remain=dividend1;
		while(remain>=divisor1){
			sftcount=0;
			cur=divisor1;
			while(remain>=cur){
				cur=(cur<<1);
				sftcount++;
			}
			remain=remain-(cur>>1);
			res=res+(0x1<<(sftcount-1));
		}
		
		if(_sign==-1)
			return (0-res);
		else
			return res;
    }
};