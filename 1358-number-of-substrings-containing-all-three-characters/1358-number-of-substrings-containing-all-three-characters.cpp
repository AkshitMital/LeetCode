class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length(), result = 0;

        unordered_map<char, int> mpp;

        int i = 0, j = 0;

        while(j < n) {
            char ch = s[j];

            mpp[ch]++;

            while(mpp.size() == 3) {
                result += (n - j);
                mpp[s[i]]--;
                if(mpp[s[i]] == 0) mpp.erase(s[i]);
                i++;
            }

            j++;
        }

        return result;
    }
};