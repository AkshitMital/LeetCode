class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> freq(26, 0);
        int MOD = 1e9 + 7;

        for(char& ch : s) freq[ch - 'a']++;

        for(int cnt = 1; cnt <= t; cnt++) {
            vector<int> temp(26, 0);
            for(int i = 0; i < 26; i++) {
                char ch = 'a' + i;
                int f = freq[i];
                if(ch != 'z') temp[(ch + 1) - 'a'] = (temp[(ch + 1) - 'a'] + f) % MOD;
                else {
                    temp[0] = (temp[0] + f) % MOD;
                    temp[1] = (temp[1] + f) % MOD;
                }
            }
            freq = move(temp);
        }

        int sum = 0;
        for(int i = 0; i < 26; i++) sum = (sum + freq[i]) % MOD;;

        return sum;
    }
};