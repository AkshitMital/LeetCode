class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> diff;
        for(int i = 0; i < s.length(); i++){
            diff.push_back(abs(s[i]-t[i]));
        }
        int l = 0, ans = INT_MIN, n = diff.size(), temp = 0;
        
        for(int r = 0; r < n; r++){
            temp += diff[r];
            
            while(temp > maxCost){
                temp -= diff[l];
                l++;
            }
            
            ans = max(ans, r - l + 1);
        }
        
        return ans;
    }
};