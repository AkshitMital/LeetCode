class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for(auto ch : expression){
            if(ch == ')'){
                bool hasT = false, hasF = false;
                while(st.top() == 't' || st.top() == 'f'){
                    if(st.top() == 'f') hasF = true;
                    if(st.top() == 't') hasT = true;
                    st.pop();
                }
                char op = st.top();
                st.pop();
                if (op == '|') st.push(hasT ? 't' : 'f');
                else if (op == '&') st.push(hasF ? 'f' : 't');
                else if (op == '!') st.push(hasT ? 'f' : 't');
            }
            else if (ch != ',' && ch != '(') st.push(ch);
        }

        return (st.top() == 't') ? true : false;
    }
};