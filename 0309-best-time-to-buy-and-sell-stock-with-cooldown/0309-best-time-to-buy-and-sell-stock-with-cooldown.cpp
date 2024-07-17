class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> prev1(2, 0), prev2(2,0), curr(2, 0);

        for(int i = n-1; i >= 0; i--){
            for(int buy = 0; buy <= 1; buy++){
                int price = 0;
                if(buy)
                    price = max(prev1[0] - prices[i], prev1[1]);
                else
                    price = max(prev2[1] + prices[i], prev1[0]);

                curr[buy] = price;
            }
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1[1];
    }
};