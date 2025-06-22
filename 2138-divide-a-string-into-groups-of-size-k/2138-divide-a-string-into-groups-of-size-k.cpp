class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        vector<string> res;
        string temp = "";

        for(int i = 0; i < n; i++) {
            if(temp.size() == k) {
                res.push_back(temp);
                temp = "";
            }
            temp.push_back(s[i]);
        }

        if(!temp.empty()) {
            while(temp.size() < k) {
                temp.push_back(fill);
            }
            res.push_back(temp);
        }

        return res;
    }
};