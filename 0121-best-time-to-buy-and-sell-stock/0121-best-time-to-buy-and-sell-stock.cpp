class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int l = 0;
        int r = 1;
        int profit = 0;
        
        while(r < n){
            if(prices[l] > prices[r]){
                l = r;
            }
            if(prices[l] <= prices[r]){
                profit = max(profit, prices[r] - prices[l]);
            }
            r++;
        }

        return profit;
    }
};