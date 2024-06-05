class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> count(26,INT_MAX);
        // for(int i = 0; i < words[0].length(); i++){
        //     count[words[0][i] - 'a']++;
        // }

        for(int i = 0; i < words.size(); i++){
            vector<int> letters(26,0);
            for(int j = 0; j < words[i].size(); j++){
                letters[words[i][j] - 'a']++;
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