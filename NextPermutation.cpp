/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 �� 1,3,2
3,2,1 �� 1,2,3
1,1,5 �� 1,5,1
*/

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
    	if(num.size()<2)
			return;
		int breakpoint=num.size()-2,ptr1,ptr2=num.size()-1;
		
		while(breakpoint>=0&&num[breakpoint]>=num[breakpoint+1])
			breakpoint--;
		
		ptr1=breakpoint+1;
		
		if(breakpoint>=0){
			int min_greater,assigned=0;
			int mgidx=breakpoint;
			for(int i=num.size()-1;i>breakpoint;i--){
				if(num[i]>num[breakpoint]&&(num[i]<min_greater||!assigned)){
					mgidx=i;
					min_greater=num[i];
					assigned=1;
				}
			}
			swap(num[breakpoint],num[mgidx]);
		}
		
		while(ptr1<ptr2){
			swap(num[ptr1++],num[ptr2--]);
		}
    }
};



    	//find the break point
        // e.g          1234768
        //                | breakpoint
        //                 | swappoint
        //  step1: swap breakpoint and swappoint
        //  step2: reverse array from breakpoint+1 to the end
