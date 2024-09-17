class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string s = s1 + " " + s2;
        unordered_map<string, int> mpp;
        string temp;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                mpp[temp]++;
                temp = "";
            }
            else temp += s[i];
        }
        mpp[temp]++;
        vector<string> res;
        for(auto& [str, cnt] : mpp){
            if(cnt == 1) res.push_back(str);
        }

        return res;
    }
};