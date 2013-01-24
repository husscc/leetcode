/*
Given a string, find the length of the longest substring without repeating characters. 
For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. 
For "bbbbb" the longest substring is "b", with the length of 1.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	if(s.size()<2)
			return s.size();
        vector<unsigned char> bs(26,0x0);
		queue<char> qu;
		int max_len=0;
		
		for(int i=0;i<s.size();i++){
			if(false==bs[(int)(s[i]-'a')]){
				bs[(int)(s[i]-'a')]=true;
				qu.push(s[i]);
			}
			else{
				max_len=max_len>qu.size()?max_len:qu.size();
				while(qu.front()!=s[i]){
					bs[(int)(qu.front()-'a')]=false;
					qu.pop();
				}
				qu.pop();
				qu.push(s[i]);
			}
		}
		
		max_len=max_len>qu.size()?max_len:qu.size();
		return max_len;
    }
};