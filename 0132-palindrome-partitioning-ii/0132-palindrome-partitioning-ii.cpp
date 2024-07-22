// class Solution {
// private:
//     bool isPalindrome(string& s){
//         int l = 0, r = s.length()-1;
//         while(l < r){
//             if(s[l] != s[r]) return false;
//             l++;
//             r--;
//         }
//         return true;
//     }
//     int solve(int i, string& s, vector<int>& dp){
//         if(i == s.length()) return 0;
//         if(dp[i] != -1) return dp[i];
//         int minCost = INT_MAX;
//         string temp = "";
//         for(int j = i; j < s.length(); j++){
//             temp += s[j];
//             if(isPalindrome(temp)) minCost = min(minCost, 1 + solve(j+1, s, dp));
//         }

//         return dp[i] = minCost;
//     }
// public:
//     int minCut(string s) {
//         vector<int> dp(s.length() + 1, -1);
//         return solve(0, s, dp) - 1;//-1 as it is putting a partition in front of the last element
//     }
// };

class Solution {
private:
    bool isPalindrome(string& s){
        int l = 0, r = s.length()-1;
        while(l < r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
public:
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n+1, 0);
        for(int i = n-1; i >= 0; i--){
            int minCost = INT_MAX;
            string temp = "";
            for(int j = i; j < n; j++){
                temp += s[j];
                if(isPalindrome(temp)) minCost = min(minCost, 1 + dp[j+1]);
            }
            dp[i] = minCost;
        }
        return dp[0] - 1; //-1 as it is putting a partition in front of the last element
    }
};