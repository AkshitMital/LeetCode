class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> diff(n + 1, 0);
        
        for(auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];
            
            int val = (direction == 0) ? -1 : 1;
            diff[start] += val;
            diff[end + 1] -= val;
        }

        for(int i = 1; i < n; i++) diff[i] += diff[i-1];
        
        for(int i = 0; i < n; i++) {
            int shift = diff[i] % 26;
            if(shift < 0) shift += 26;

            s[i] = (((s[i] - 'a') + shift) % 26) + 'a';
        }
        
        return s;
    }
};