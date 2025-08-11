class Solution {
public:
    int MOD = 1e9 + 7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int power = 0;
        vector<int> powers;
        while(n) {
            if((n & 1) == 1) {
                powers.push_back(pow(2, power));
            }
            power++;
            n = n >> 1;
        }

        vector<int> ans;
        for (const auto& query : queries) {
            int cur = 1;
            for (int i = query[0]; i <= query[1]; ++i) {
                cur = static_cast<long long>(cur) * powers[i] % MOD;
            }
            ans.push_back(cur);
        }
        return ans;
    }
};

/*
1 2 8 512 65536 67108864 {438952513 949480669 582344008 496641140 747046415 468085851 585862415 53483165 605287554} 928968775 745327334 
*/