/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

0000 - 0
0001 - 1		0	
0011 - 3		1	<-
0010 - 2		0	->

0110 - 6		2	
0111 - 7		0	
0101 - 5		1	<-
0100 - 4		0	->

1100 - 12		3
1101			0
1111			1
1110			0
1011			2
1010			0
1001			1
1000			0

Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*/
class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
        res.push_back(0x0);
    	if(n<1)
			return res;
		
		res.push_back(0x1);
		int loop=0x1,mask=0x1<<1;
		if(n<=32)
			loop=(loop<<(n-1));
		
		while(mask!=0&&mask<=loop){
			for(int ptr=res.size()-1;ptr>=0;ptr--){
				res.push_back(res[ptr]^mask);
			}
			mask=(mask<<1);
		}
		return res;
    }
};