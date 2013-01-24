/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	assert(rowIndex>=0);
		
		vector<int> *v1=new vector<int>;
		(*v1).resize(rowIndex+1);
		vector<int> *v2=new vector<int>;
		(*v2).resize(rowIndex+1);
		
		(*v1)[0]=1;
		for(int i=1;i<rowIndex+1;i++){
			(*v2)[0]=1;
			for(int j=1;j<i;j++)
				(*v2)[j]=(*v1)[j-1]+(*v1)[j];
			(*v2)[i]=1;
			
            vector<int> *p=v1;
			v1=v2;
            v2=p;
		}
		return *v1;
    }
};