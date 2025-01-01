

/*
    Leetcode Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0; // To store the maximum profit found so far
        int profit = 0; // To store the profit for the current transaction
        int buy = prices[0]; // Initialize 'buy' to the first price
        
        // Iterate through the price list starting from the second element
        for(int i = 1; i < prices.size(); i++)
        {
            // Calculate the potential profit if selling on the current day
            profit = prices[i] - buy;
            
            // Update the maximum profit if the current profit is greater
            maxi = max(maxi, profit);

            // Update the 'buy' price to the minimum price seen so far
            buy = min(buy, prices[i]);
        }
        return maxi; // Return the maximum profit
    }
};
