class Solution {
public:
    string smallestNumber(string pattern) {
        string num;
        stack<char> st;
        int counter = 1, n = pattern.length();

        for(int i = 0; i <= n; i++) {
            st.push(counter + '0');
            counter++;

            if(i == n || pattern[i] == 'I') {
                while(!st.empty()) {
                    num += st.top();
                    st.pop();
                }
            }
        }

        return num;
    }
};