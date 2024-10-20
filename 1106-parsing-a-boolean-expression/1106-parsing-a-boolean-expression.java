class Solution {
    public boolean parseBoolExpr(String expression) {
        Stack<Character> st = new Stack<>();
        for(char ch : expression.toCharArray()){
            if(ch == '(' || ch == ',') continue;

            else if(ch == ')'){
                boolean hasF = false, hasT = false;
                while(st.peek() == 't' || st.peek() == 'f'){
                    if(st.peek() == 't') hasT = true;
                    if(st.peek() == 'f') hasF = true;
                    st.pop();
                }
                char op = st.peek();
                st.pop();
                if(op == '!'){
                    if(hasF) st.push('t');
                    else st.push('f');
                }
                else if(op == '&'){
                    if(hasF && hasT) st.push('f');
                    else if(hasF && !hasT) st.push('f');
                    else st.push('t');
                }
                else{
                    if(hasF && hasT) st.push('t');
                    else if(hasF && !hasT) st.push('f');
                    else st.push('t');
                }
            }

            else st.push(ch);
        }

        return (st.peek() == 't') ? true : false;
    }
}