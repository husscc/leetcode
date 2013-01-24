/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

Solve this problem
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.size()==0)
			return 0;
		
        int len=0,max_len=0;
    	stack<unsigned int> sk;
		for(int i=0;i<s.size();i++){
			switch(s[i])
			{
				case '(':
					sk.push(i);
					len++;
					break;
				case ')':
					if(!sk.empty()){
						len++;
						sk.pop();
					}
					else{
						max_len=max(max_len,len);
						len=0;
					}
					break;
			}
		}
		if(!sk.empty()){
			int p1=s.size(),len_mirror=0;
			while(!sk.empty()){
				int tmp=p1-sk.top();
				len_mirror=len_mirror>(tmp-1)?len_mirror:(tmp-1);
				len=len-tmp;
				p1=sk.top();
				sk.pop();
			}
            len=max(len,len_mirror);
		}
		
        max_len=max(max_len,len);
		return max_len;
    }
};