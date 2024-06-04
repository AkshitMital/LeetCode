class Solution {
public:
    int longestPalindrome(string s) {
        int odd = 0;
        unordered_map<char, int> mpp;
        for(auto ch : s){
            mpp[ch]++;
            if(mpp[ch] % 2 == 1){
                odd++;
            }else{
                odd--;
            }
        }
        return (odd > 1) ? s.length() - odd + 1 : s.length();
    }
};