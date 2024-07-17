class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> prev(2, 0), curr(2, 0);

        for(int i = n-1; i >= 0; i--){
            for(int buy = 0; buy <= 1; buy++){
                int price = 0;
                if(buy)
                    price = max(prev[0] - prices[i] - fee, prev[1]);
                else
                    price = max(prev[1] + prices[i], prev[0]);

                curr[buy] = price;
            }
            prev = curr;
        }

        return prev[1];
    }
};