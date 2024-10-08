class Solution {
public:
    int minSwaps(string s) {
        stack<int> st;
        int swap = 0;
        for(char ch : s){
            if(ch == '[') st.push(ch);
            else{
                if(!st.empty()) st.pop();
                else swap++;
            }
        }

        return (swap + 1)/2;
    }
};