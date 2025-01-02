class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> ans, prefix(n, 0);

        for(int i = 0; i < n; i++){
            string word = words[i];
            int l = 0, r = word.size() - 1;

            if((word[r] == 'a' || word[r] == 'e' || word[r] == 'i' || word[r] == 'o' || word[r] == 'u') && (word[l] == 'a' || word[l] == 'e' || word[l] == 'i' || word[l] == 'o' || word[l] == 'u')){
                prefix[i] = 1;
            }

            if(i > 0) prefix[i] += prefix[i-1];
        }

        for(auto query : queries){
            int l = query[0], r = query[1];
            if(l == 0) ans.push_back(prefix[r]);
            else ans.push_back(prefix[r] - prefix[l-1]);
        }

        return ans;
    }
};