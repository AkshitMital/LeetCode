class Solution {
public:
    int maxScore(string s) {
        int total0 = 0, total1 = 0, n = s.length();
        for(int i = 0; i < n; i++){
            if(s[i] == '0') total0++;
            if(s[i] == '1') total1++;
        }
        int curr0 = 0, curr1 = 0, ans = 0;
        for(int i = 0; i < n - 1; i++){
            if(s[i] == '0'){
                curr0++;
                if(total0 != 0) total0--;
            }
            if(s[i] == '1'){
                curr1++;
                if(total1 != 0) total1--;
            }

            ans = max(ans, curr0 + total1);
        }

        return ans;
    }
};