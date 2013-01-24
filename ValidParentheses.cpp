/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/
class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<char> pstack;
    	for(int i=0;i<s.size();i++){
			if(s[i]=='('||s[i]=='['||s[i]=='{')
				pstack.push(s[i]);
			else{
				if(pstack.empty())
					return false;
				else{
					switch(s[i]){
						case ')':
							if(pstack.top()!='(')
								return false;
							break;
						case ']':
							if(pstack.top()!='[')
								return false;
							break;
						case '}':
							if(pstack.top()!='{')
								return false;
							break;
						default:
							return false;
					}
					pstack.pop();
				}
			}
		}
		if(pstack.empty())
			return true;
		else
			return false;
    }
};