class Solution {
    
    string permutation(string s){
        if(s.size()<2)
            return s;
        else{
            string res;
            res=s.at(s.size()-1);
            s.erase(s.end()-1);
            return res+s;
        }
    }
    
    struct str_hash{
        size_t operator()(const string& str)const{
            return __stl_hash_string(str.c_str());
        }
    };
    /*
    struct str_compare{
        bool operator()(const string& str1,const string& str2)const{
            return str1==str2;
        }
    };*/
    
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> res;
        vector<string>::iterator iter1;
        res.clear();
        string target,perm;
        int tarlen,fsize,asize;
        
        hash_map<string,int,str_hash> hm;
    	hash_map<string,int,str_hash>::iterator iter2;
        hm.clear();
        
        for(iter1=strs.begin();iter1!=strs.end();iter1++){
            if((hm.find(*iter1))==hm.end()){
    			hm.insert(pair<string,int>(*iter1,1));
			}
			else
				hm[*iter1]++;
        }
        
		bool self;
		while(hm.size()>0){
			target=hm.begin()->first;
            self=false;
			if(hm[target]>1){
                self=true;
				for(int i=0;i<hm[target];i++)
					res.push_back(target);
			}
			hm.erase(target);
			
			tarlen=target.size();
			perm=permutation(target);
			
            fsize=res.size();
			for(int i=1;i<tarlen;i++){
				if(hm.find(perm)!=hm.end()){
					for(int j=0;j<hm[perm];j++)
						res.push_back(perm);
					hm.erase(perm);
				}
				perm=permutation(perm);
			}
            asize=res.size();
            if(asize!=fsize&&!self)
                res.push_back(target);
		}
		
		return res;
		/*
        while(strs.size()>0){
            target=strs.back();
            strs.erase(strs.end()-1);
            perm=target;
            tarlen=target.size();
            
            fsize=res.size();
            for(int i=0;i<tarlen;i++){
                iter1=strs.begin();
                while((iter1=find(iter1,strs.end(),perm))!=strs.end()){
                    res.push_back(*iter1);
                    iter1=strs.erase(iter1);
                }

                perm=permutation(perm);

            }
            asize=res.size();
            if(asize>fsize)
                res.push_back(target);
        }*/
        
        return res;
        
    }
};