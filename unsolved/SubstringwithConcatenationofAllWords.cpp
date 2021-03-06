/*
You are given a string, S, and a list of words, L, that are all of the same length. 
Find all starting indices of substring(s) in S that is 
a concatenation of each word in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/
class Solution {
    struct str_hash{
        size_t operator()(const string &s)const{
    		return __stl_hash_string(s.c_str());
		}
	};
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
		int slen=S.size(),llen=L.size();
		
		if(!slen||!llen)
			return res;
		
		int wlen=L[0].size(),wclen=0;
		int *wordcount=new int[llen];
		//use hash map to store indices of word_count array
		hash_map<string,int,str_hash> hm;
		
		for(int i=0;i<llen;i++){
			if(!hm.count(L[i])){
				hm.insert(pair<string,int>(L[i],wclen));
				wordcount[wclen]=1;
                wclen++;
			}
			else
				wordcount[hm[L[i]]]++;
		}
		
		int *check=new int[wclen];
		for(int i=0;i<slen-llen*wlen+1;i++){
			
            memcpy(check,wordcount,wclen*sizeof(int));
            
			int j=i;
			for(;j<i+llen*wlen;j+=wlen){
                string str=S.substr(j,wlen);
				if(hm.count(str)&&check[hm[str]])
					check[hm[str]]--;
				else
					break;
			}
			
			if(j==i+llen*wlen)
				res.push_back(i);
		}
		delete []wordcount;
        delete []check;
		return res;
    }
};