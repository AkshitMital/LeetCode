class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.length();
        stack<char> st;
        int ans = 0;
        string firstpair, secondpair;
        if(x > y){
            firstpair = "ab";
            secondpair = "ba";
        }else{
            secondpair = "ab";
            firstpair = "ba";
        }

        for(int i = 0; i < n; i++){
            if(!st.empty() && st.top() == firstpair[0] && s[i] == firstpair[1]){
                st.pop();
                ans += max(x,y);
            }
            else{
                st.push(s[i]);
            }
        }

        string temp;
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }

        reverse(temp.begin(), temp.end());

        for(int i = 0; i < temp.size(); i++){
            if(!st.empty() && st.top() == secondpair[0] && temp[i] == secondpair[1]){
                st.pop();
                ans += min(x,y);
            }
            else{
                st.push(temp[i]);
            }
        }

        return ans;
    }
};