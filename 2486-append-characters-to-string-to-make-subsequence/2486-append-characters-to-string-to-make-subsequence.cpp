class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0;
        while(i < s.size() && i < t.size() && s[i] == t[i]) {
            i += 1;
        }

        return t.size() - i;
    }
};