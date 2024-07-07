class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles, total = numBottles;
        if(numBottles < numExchange) return ans;

        while(total >= numExchange){
            int div = total / numExchange;
            int mod = total % numExchange;
            total = div + mod;
            ans += div;
        }

        return ans;
    }
};