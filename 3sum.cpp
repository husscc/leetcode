class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(),num.end());
    	int arlen=num.size();
		vector<int> tmpVec;
		vector<vector<int> > res;
		res.clear();
		if(arlen<3)
			return res;
		
		int fprint,_base=num[arlen-1]-num[0];
		hash_set<int> hs;
		hs.clear();
        //hs.resize((arlen*(arlen-1)*(arlen-2))/6);
		for(int i=0;i<arlen-2;i++){
			for(int j=i+1;j<arlen-1;j++){
				for(int k=j+1;k<arlen;k++){
					if(num[i]+num[j]+num[k]==0){
						tmpVec.clear();
						tmpVec.push_back(num[i]);
						tmpVec.push_back(num[j]);
						tmpVec.push_back(num[k]);
						
						
						fprint=(tmpVec[0]-num[0])*_base*_base+(tmpVec[1]-num[0])*_base+(tmpVec[2]-num[0]);
						if(!hs.count(fprint)){
							hs.insert(fprint);
							res.push_back(tmpVec);
						}
						
					}
				}
			}
		}
		return res;
    }
};