class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int emptyBottles = numBottles, ans = numBottles;
        
        while(emptyBottles >= numExchange) {
            emptyBottles -= numExchange;
            ans++;
            emptyBottles++;
            numExchange++;
        }

        return ans;
    }
};