/*
Best Time to Buy and Sell Stock III
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(prices.size()<2)
			return 0;
		if(prices.size()==2)
			return (prices[1]-prices[0]>0)?(prices[1]-prices[0]):0;
		
		if(prices.size()==3){
			int res=0;
			res=res>(prices[1]-prices[0])?res:(prices[1]-prices[0]);
			res=res>(prices[2]-prices[1])?res:(prices[2]-prices[1]);
			res=res>(prices[2]-prices[0])?res:(prices[2]-prices[0]);
			return res;
		}
		
		vector<int> profit1(prices.size(),0);
		vector<int> profit2(prices.size(),0);
		
		int lowprice=0,maxprofit=0;
		
		for(int i=0;i<prices.size();i++){
			lowprice=prices[lowprice]<prices[i]?lowprice:i;
			maxprofit=maxprofit>(prices[i]-prices[lowprice])?maxprofit:(prices[i]-prices[lowprice]);
			profit1[i]=maxprofit;
		}
		
		profit2[0]=profit1[prices.size()-1];
		maxprofit=0;
		int highprice=prices.size()-1;
		for(int i=prices.size()-1;i>0;i--){
			highprice=prices[highprice]>prices[i]?highprice:i;
			maxprofit=maxprofit>(prices[highprice]-prices[i])?maxprofit:(prices[highprice]-prices[i]);
			profit2[i]=maxprofit;
		}
		
		maxprofit=profit1[0];
		for(int i=0;i<prices.size()-1;i++){
			maxprofit=maxprofit>(profit1[i]+profit2[i+1])?maxprofit:(profit1[i]+profit2[i+1]);
		}
		
		return maxprofit;
    }
};