class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);
        for(char& ch : word) freq[ch - 'a']++;

        sort(freq.begin(), freq.end());

        int res = INT_MAX, cum_del = 0;
        for(int i = 0; i < 26; i++) {
            int minFreq = freq[i];
            int del = cum_del;
            for(int j = 25; j > i; j--) {
                if(freq[j] - freq[i] <= k) break;

                del += (freq[j] - minFreq - k);
            }

            res = min(res, del);
            cum_del += minFreq;
        }

        return res;
    }
};