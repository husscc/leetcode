/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, 
where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/
class Solution {
    int findnum(vector<int> &numbers,int start,int target){
		while(start<numbers.size()){
			if(numbers[start]==target)
				return start+1;
            start++;
		}
		return 0;
	}
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<int> res(2,0);
		for(int i=0;i<numbers.size()-1;i++){
			if(int index=findnum(numbers,i+1,target-numbers[i])){
				res[0]=i+1;
				res[1]=index;
			}
		}
		return res;
    }
};