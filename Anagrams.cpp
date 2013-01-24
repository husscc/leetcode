/*
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
*/
class Solution {    
    
    struct str_hash{
        size_t operator()(const string& str)const{
            return __stl_hash_string(str.c_str());
        }
    };
    
    struct compstr{
        bool operator()(const char a,const char b){
            return a<=b;
        }
    };
    
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> res;
        res.clear();
        string target,strcode;
        int tarlen,fsize,asize;
        
        hash_map<string,vector<string>,str_hash> hm;
		
		for(vector<string>::iterator iter=strs.begin();iter!=strs.end();iter++){
			string target=*iter;
            strcode=target;
            if(strcode.size()>1)
                sort(&strcode[0],&strcode[strcode.size()],compstr());
			
			if(!hm.count(strcode)){
				vector<string> val(1,target);
				hm.insert(pair<string,vector<string> >(strcode,val));
			}
			else
				hm[strcode].push_back(target);
		}
		
		for(hash_map<string,vector<string>,str_hash>::iterator iter=hm.begin();iter!=hm.end();++iter){
			if((iter->second.size())>1){
				for(int i=0;i<(iter->second).size();i++)
					res.push_back((iter->second)[i]);
			}
		}
        
        return res;
        
    }
};