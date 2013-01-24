/*
Given a string, determine if it is a palindrome, 
considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? 
This is a good question to ask during an interview.

For the purpose of this problem, 
we define empty string as valid palindrome.
*/
class Solution {
	inline char toLowerCase(const char a){
		if(isupper(a))
			return 'a'+(a-'A');
		else
			return a;
	}
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int start=0,end=s.size()-1;
		while(start<end){
			if(!isalpha(s[start])&&!isdigit(s[start]))
				start++;
			else if(!isalpha(s[end])&&!isdigit(s[end]))
				end--;
			else if(s[start]==s[end]||toLowerCase(s[start])==toLowerCase(s[end])){
				start++;
				end--;
			}
			else 
				return false;
		}
		return true;
    }
};
