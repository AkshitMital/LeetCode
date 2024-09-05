class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size(), sum = 0;
        for(int& roll : rolls) sum += roll;
        int nTotal = (mean * (n+m)) - sum;

        if(nTotal < n || nTotal > n*6) return {};

        vector<int> res;
        while(nTotal > 0){
            int dice = min(nTotal - n + 1, 6);
            res.push_back(dice);
            nTotal -= dice;
            n--;
        }

        return res;
    }
};