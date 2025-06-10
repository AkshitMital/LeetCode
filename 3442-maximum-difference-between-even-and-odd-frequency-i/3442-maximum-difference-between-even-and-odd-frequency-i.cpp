class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26, 0);

        for(char& ch : s) freq[ch - 'a']++;

        int minEvenFreq = INT_MAX;
        int maxOddFreq = INT_MIN;
        for(int i = 0; i < 26; i++) {
            if(freq[i] == 0) continue;

            if(freq[i] % 2 == 0) minEvenFreq = min(minEvenFreq, freq[i]);
            else maxOddFreq = max(maxOddFreq, freq[i]);
        }

        return maxOddFreq - minEvenFreq;
    }
};