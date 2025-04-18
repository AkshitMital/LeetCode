class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";

        string s = countAndSay(n - 1);

        string result = "";

        for(int i = 0; i < s.length(); i++) {
            int cnt = 1;
            char ch = s[i];

            while(i < s.length() - 1 && s[i] == s[i + 1]) {
                i++;
                cnt++;
            }

            result += (to_string(cnt) + string(1, ch));
        }

        return result;
    }
};