/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), 
design an algorithm to find the maximum profit.
*/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!prices.size())
			return 0;
		int lowprice=prices[0],maxprofit=0;
		
		for(int i=0;i<prices.size();i++){
			lowprice=lowprice<prices[i]?lowprice:prices[i];
			maxprofit=maxprofit>(prices[i]-lowprice)?maxprofit:(prices[i]-lowprice);
		}
		
		return maxprofit;
    }
};