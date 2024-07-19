class Solution {
private:
    bool isCheck(string& s1, string& s2){
        if(s1.size() != s2.size() + 1) return false;
        int first = 0, second = 0;
        while(first < s1.size()){
            if(s1[first] == s2[second]){
                first++;
                second++;
            }else{
                first++;
            }
        }
        if(first == s1.size() && second == s2.size()) return true;
        return false;
    }
public:
    int longestStrChain(vector<string>& words) {
        auto lambda = [](string& s1, string& s2){
            return s1.size() < s2.size();
        };
        sort(words.begin(), words.end(), lambda);
        int n = words.size();
        vector<int> dp(n, 1);

        for(int i = 0; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(isCheck(words[i], words[prev]) && 1 + dp[prev] > dp[i])
                    dp[i] = 1 + dp[prev];
            }
        }

        int ans = *max_element(dp.begin(), dp.end());

        return ans;
    }
};