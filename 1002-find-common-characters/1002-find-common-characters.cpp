class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> count(26,INT_MAX);

        for(auto word : words){
            vector<int> letters(26,0);
            for(auto ch : word){
                letters[ch - 'a']++;
            }
            for(int k = 0; k < 26; k++){
                count[k] = min(count[k], letters[k]);
            }
        }

        vector<string> ans;

        for(int i = 0; i < 26; i++){
            while(count[i]--){
                ans.push_back(string(1, i + 'a'));
            }
        }
        
        return ans;
    }
};