class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        string ans = "";
        int num = 0;

        for(char ch : s){
            if(isdigit(ch)) num = num * 10 + (ch - '0');
            else if(ch == '['){
                st.push(ans);
                st.push(to_string(num));
                ans = "";
                num = 0;
            }
            else if(ch == ']'){
                string numStr = st.top(); st.pop();
                string str = st.top(); st.pop();

                int num = stoi(numStr);
                string temp = ans;

                while(num--) str += temp;
                ans = str;
            }
            else ans += ch;
        }

        return ans;
    }
};