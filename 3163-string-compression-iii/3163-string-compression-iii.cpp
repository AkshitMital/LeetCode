class Solution {
public:
    string compressedString(string word) {
        int n = word.size(), i = 0, j = 0, count = 0;
        
        string ans = "";
        
        while(j < n){
            while(j < n && word[i] == word[j] && count < 9){
                count++;
                j++;
            }
            ans += (to_string(count) + word[i]);
            i = j;
            count = 0;
        }
        
        return ans;
    }
};