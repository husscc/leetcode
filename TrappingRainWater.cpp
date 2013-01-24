/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/
class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n<3)
            return 0;
			
		vector<int> summit;
        bool up=true;
		
		for(int i=0;i<n-1;i++){
			if(up&&A[i]>A[i+1]){
				summit.push_back(i);
				up=false;
			}
			else if(!up&&A[i]<A[i+1])
				up=true;
		}
		if(up)
			summit.push_back(n-1);
		
		int volume=0,smsize=summit.size();
        
		for(int i=0;i<smsize-1;){		
			
			int peak=summit[i],p=i+1,j=i+1;
			while(j<smsize&&A[peak]>A[summit[j]]){
				if(A[summit[j]]>=A[summit[p]])
					p=j;
				j++;
			}
			
			if(j==smsize){
				for(int k=peak+1;k<summit[p];k++){
					if(A[summit[p]]>A[k])
                        volume+=A[summit[p]]-A[k];
				}
				i=p;
			}
			else{
				for(int k=peak+1;k<summit[j];k++){
					if(A[peak]>A[k])
                        volume+=A[peak]-A[k];
				}
				i=j;
			}
		}
		return volume;
    }
};