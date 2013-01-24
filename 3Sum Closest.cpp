class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int min=-1,len=num.size(),res;
        
        for(int i=0;i<len-2;i++){
            for(int j=i+1;j<len-1;j++){
                for(int k=j+1;k<len;k++){
                    if(min<0||(abs(target-num[i]-num[j]-num[k])<min)){
                        res=num[i]+num[j]+num[k];
                        min=abs(target-num[i]-num[j]-num[k]);
                    }
                    
                    if(min==0)
                        return res;
                }
            }
        }
        
        return res;
    }
};