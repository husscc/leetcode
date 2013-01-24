/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
(ie, buy one and sell one share of the stock multiple times). 
However, you may not engage in multiple transactions at the same time 
(ie, you must sell the stock before you buy again).
*/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(prices.size()<2)
        	return 0;
		if(prices.size()==2){
			if(prices[1]>prices[0])
				return prices[1]-prices[0];
			else
				return 0;
		}
		
		int lastbuy=-1,lastsell=-1,profit=0;
		
		if(prices[0]<prices[1])
			lastbuy=0;
		
		for(int i=1;i<prices.size()-1;i++){
			if((lastbuy==-1||lastsell>lastbuy)&&(prices[i]<prices[i+1]&&prices[i]<=prices[i-1])){
				lastbuy=i;
			}
			else if((lastbuy>lastsell)&&(prices[i]>prices[i+1]&&prices[i]>=prices[i-1])){
				profit+=prices[i]-prices[lastbuy];
				lastsell=i;
			}	
		}
		
		if(lastbuy>lastsell)
			profit+=prices[prices.size()-1]-prices[lastbuy];
		return profit;
    }
};

