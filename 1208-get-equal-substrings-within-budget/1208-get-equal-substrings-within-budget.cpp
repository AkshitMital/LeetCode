class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        
        int l = 0, ans = INT_MIN, n = s.size(), temp = 0;
        
        for(int r = 0; r < n; r++){
            temp += abs(s[r]-t[r]);
            
            while(temp > maxCost){
                temp -= abs(s[l]-t[l]);
                l++;
            }
            
            ans = max(ans, r - l + 1);
        }
        
        return ans;
    }
};