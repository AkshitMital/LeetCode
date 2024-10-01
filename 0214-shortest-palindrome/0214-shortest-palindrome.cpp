class Solution {
private:
    int computeLPS(string& temp, int n){
        vector<int> LPS(n, 0);
        int i = 1, len = 0;
        while(i < n){
            if(temp[len] == temp[i]){
                len++;
                LPS[i] = len;
                i++;
            }
            else{
                if(len == 0){
                    LPS[i] = 0;
                    i++;
                }
                else len = LPS[len-1];
            }
        }

        return LPS[n-1];
    }
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string temp = s + "#" + rev;
        int LPS = computeLPS(temp, temp.size());
        string culprit = rev.substr(0, s.length() - LPS);

        return culprit + s;
    }
};