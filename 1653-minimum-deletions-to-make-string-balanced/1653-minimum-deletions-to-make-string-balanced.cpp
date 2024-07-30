// class Solution {
// public:
//     int minimumDeletions(string s) {
//         stack<char> st;
//         int ans = 0;
//         for(int i = 0; i < s.length(); i++){
//             if(!st.empty() && s[i] == 'a' && st.top() == 'b'){
//                 st.pop();
//                 ans++;
//             }
//             else st.push(s[i]);
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int minimumDeletions(string s) {
        int total_a = 0;
        for(char ch : s){
            if(ch == 'a') total_a++;
        }

        int count_b = 0, ans = INT_MAX;

        for(char ch : s){
            if(ch == 'a') total_a--;
            ans = min(ans, total_a + count_b);
            if(ch == 'b') count_b++;
        }

        return ans;
    }
};