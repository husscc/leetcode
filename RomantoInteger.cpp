/*
Given a roman numeral, convert it to an integer.

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
public:
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	int slen=s.size(),res=0;
		if(!slen)
			return res;
		
        hash_map<char,int> valtb;
		valtb.insert(pair<char,int>('M',1000));
		valtb.insert(pair<char,int>('D',500));
		valtb.insert(pair<char,int>('C',100));
		valtb.insert(pair<char,int>('L',50));
		valtb.insert(pair<char,int>('X',10));
		valtb.insert(pair<char,int>('V',5));
		valtb.insert(pair<char,int>('I',1));
		
		//char symbol[7]={'I','V','X','L','C','D','M'};
		
        char crbase='I';
		for(int i=slen-1,crbase=0;i>=0;i--){
			if(valtb[s[i]]==valtb[crbase])
                res+=valtb[s[i]];
            else if(valtb[s[i]]>valtb[crbase]){
				crbase=s[i];
				res+=valtb[s[i]];
			}
			else
				res-=valtb[s[i]];
		}
		return res;
    }
};