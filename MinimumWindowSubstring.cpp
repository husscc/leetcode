/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/
class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string str="";
		if(!S.size()||!T.size())
			return str;
			
		int count=T.size(),pS;
		hash_map<char,int> hm;
		queue<char> q_char;
		queue<int> q_pos;
		
		for(int i=0;i<count;i++){
			if(!hm.count(T[i]))
				hm.insert(pair<char,int>(T[i],-1));					// abs(hm[T[i]]) = the count of T[i] in array T
			else
				hm[T[i]]--;
		}
		
		for(pS=0;count&&pS<S.size();pS++){
			if(hm.count(S[pS])){
				if(hm[S[pS]]<0)
					count--;
				
				hm[S[pS]]++;
				q_char.push(S[pS]);
				q_pos.push(pS);
				
				while(hm[q_char.front()]>0){
					hm[q_char.front()]--;
					q_char.pop();
					q_pos.pop();
				}
			}
		}
		
		if(count&&pS==S.size())
			return str;
		
		int min_len=q_pos.back()-q_pos.front()+1;
		int start_str=q_pos.front();
		
		for(;pS<S.size();pS++){
			if(hm.count(S[pS])){
				
				hm[S[pS]]++;
				q_char.push(S[pS]);
				q_pos.push(pS);
				
				while(hm[q_char.front()]>0){
					hm[q_char.front()]--;
					q_char.pop();
					q_pos.pop();
				}

				if(min_len>(pS-q_pos.front()+1)){
					min_len=(pS-q_pos.front()+1);
					start_str=q_pos.front();
				}
			}
		}
		
		str=S.substr(start_str,min_len);
		return str;
    }
};