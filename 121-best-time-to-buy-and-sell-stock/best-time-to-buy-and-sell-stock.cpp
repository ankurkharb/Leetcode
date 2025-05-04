class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minimum=prices[0];
        int max_profit=0;
        for(int i=0;i<n;i++)
        {
            int profit = prices[i] - minimum;
            minimum = min(minimum,prices[i]);
            max_profit = max(max_profit,profit);
        }
        return max_profit;
    }
};