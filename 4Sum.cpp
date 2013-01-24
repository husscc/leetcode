class Solution {
    
public:
    
    struct str_hash{    //hash function for string
        size_t operator() (const string& str) const{
            return __stl_hash_string(str.c_str());
        }
    };

    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int arlen=num.size();
		vector<int> tmpVec;
		vector<vector<int> > res;
		res.clear();
		if(arlen<4)
			return res;
        
        sort(num.begin(),num.end());
        int max=num[arlen-1],min=num[0],total1,total2,total3;
		hash_set<string,str_hash> hs;
        string fprint;
        ostringstream oss;
		hs.clear();
		for(int i=0;(i<arlen-3)&&((num[i]<=target)||num[i]<=0);i++){
			for(int j=i+1;(j<arlen-2)&&(((total1=num[i]+num[j])<=target)||num[j]<=0);j++){
				for(int k=j+1;(k<arlen-1)&&(((total2=total1+num[k])<=target)||num[k]<=0);k++){
                    for(int l=k+1;(l<arlen)&&(((total3=total2+num[l])<=target)||num[l]<=0);l++){
					    if(total3==target){
						    tmpVec.clear();
						    tmpVec.push_back(num[i]);
						    tmpVec.push_back(num[j]);
						    tmpVec.push_back(num[k]);
						    tmpVec.push_back(num[l]);
                            sort(tmpVec.begin(),tmpVec.end());
						    
                            oss<<tmpVec[0]<<tmpVec[1]<<tmpVec[2]<<tmpVec[3];
                            fprint=oss.str();
                            oss.str("");
					    	
						    if(!hs.count(fprint)){ //use hashset to check if duplicate exists
						    	hs.insert(fprint);
							    res.push_back(tmpVec);
					    	}
					    }
						
					}
				}
			}
		}
		return res;
    }
};