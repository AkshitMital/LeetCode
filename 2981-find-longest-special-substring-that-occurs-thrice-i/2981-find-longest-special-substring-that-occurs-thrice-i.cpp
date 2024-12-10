class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();
        map<pair<char, int>, int> mpp;

        for(int i = 0; i < n; i++){
            char ch = s[i];
            int len = 0;
            for(int j = i; j < n; j++){
                if (s[j] == ch){
                    len++;
                    mpp[{ch, len}]++;
                }
                else break;
            }
        }

        int res = 0;
        for(auto& it : mpp){
            int len = it.first.second;
            int freq = it.second;
            if(freq >= 3) res = max(res, len);
        }

        return (res == 0) ? -1 : res;
    }
};