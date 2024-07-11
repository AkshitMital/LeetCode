class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> stk;
        for (char c : s) {
            if (c == ')') {
                // When we encounter a closing parenthesis, we need to reverse the content inside the parentheses.
                string temp;
                while (!stk.empty() && stk.top() != '(') {
                    temp += stk.top();
                    stk.pop();
                }
                // Pop the opening parenthesis
                if (!stk.empty() && stk.top() == '(') {
                    stk.pop();
                }
                // Push the reversed string back onto the stack
                for (char ch : temp) {
                    stk.push(ch);
                }
            } else {
                // Push the current character onto the stack
                stk.push(c);
            }
        }
        // Construct the final answer from the stack
        string ans;
        while (!stk.empty()) {
            ans = stk.top() + ans;
            stk.pop();
        }
        return ans;
    }
};
