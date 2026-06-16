class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int prev_min = INT_MAX;
        for(int i=0; i<prices.size(); i++){
            int profit = prices[i] - prev_min;
            max_profit = max(max_profit, profit);
            prev_min = min(prices[i], prev_min);
        }
        return max_profit;
    }
};
