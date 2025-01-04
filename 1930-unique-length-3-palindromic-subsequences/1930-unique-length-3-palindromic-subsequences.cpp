class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<pair<int,int>> letters(26, {-1, -1});
        for(int i = 0; i < s.length(); i++){
            int idx = s[i] - 'a';
            if(letters[idx].first == -1) letters[idx].first = i;
            if(letters[idx].first != -1) letters[idx].second = i;
        }

        int ans = 0;

        for(int i = 0; i < 26; i++){
            int first_idx = letters[i].first;
            int last_idx = letters[i].second;

            if(first_idx == -1 || last_idx == -1) continue;

            unordered_set<char> st;
            for(int idx = first_idx + 1; idx <= last_idx-1; idx++){
                st.insert(s[idx]);
            }

            ans += st.size();
        }

        return ans;
    }
};