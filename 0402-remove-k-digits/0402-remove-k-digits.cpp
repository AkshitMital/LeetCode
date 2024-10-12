class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for (int i = 0; i < num.length(); i++) {
            // Remove the digit from stack while it is greater than the current digit
            // and we still have some `k` digits to remove
            while (!st.empty() && k > 0 && st.top() > num[i]) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        // If `k` is still greater than 0, pop the remaining digits from the stack
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // Now, build the result from the stack
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        // Reverse the string to get the correct order
        reverse(ans.begin(), ans.end());

        // Remove leading zeros
        int start = 0;
        while (start < ans.size() && ans[start] == '0') start++;
        ans = ans.substr(start);

        // If the result is empty after removing leading zeros, return "0"
        if (ans.empty()) return "0";

        return ans;
    }
};
