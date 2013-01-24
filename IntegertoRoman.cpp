/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/
/*
1		I
5		V
10		X
50		L
100		C
500		D
1000	M
*/
class Solution {
    inline int nextbase(int base){
    	if(base==1000||base==100||base==10||base==1)
			return base/2;
		else 
			return base/5;
	}
	inline bool isOne(int base){
		if(base==1000||base==100||base==10||base==1)
			return true;
		else
			return false;
	}
public:
    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        hash_map<int,char> htable;
		htable.insert(pair<int,char>(1000,'M'));
		htable.insert(pair<int,char>(500,'D'));
		htable.insert(pair<int,char>(100,'C'));
		htable.insert(pair<int,char>(50,'L'));
		htable.insert(pair<int,char>(10,'X'));
		htable.insert(pair<int,char>(5,'V'));
		htable.insert(pair<int,char>(1,'I'));
		int base=1000;
		int count;
		string res="";
		while(num>0){
			if(isOne(base)&&
				(num<base&&(num+nextbase(nextbase(base)))>=base)){
				res=res+htable[nextbase(nextbase(base))]+htable[base];
				num=num-(base-nextbase(nextbase(base)));
				base=nextbase(nextbase(base));
			}
			else if(!isOne(base)&&
				(num<base&&(num+nextbase(base))>=base)){
				res=res+htable[nextbase(base)]+htable[base];
				num=num-(base-nextbase(base));
				base=nextbase(nextbase(base));
			}
            else if(!isOne(base)&&
				(num<2*base&&(num+nextbase(base))>=2*base)){
				res=res+htable[nextbase(base)]+htable[2*base];
				num=num-(2*base-nextbase(base));
				base=nextbase(nextbase(base));
			}
			else{
				count=num/base;
				num=num%base;
				for(int i=0;i<count;i++)
					res+=htable[base];
				base=nextbase(base);
			}
		}
		return res;
    }
};