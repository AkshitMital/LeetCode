class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int backs = 0, backt = 0, i = s.size()-1, j = t.size()-1;

        while(i >= 0 || j >= 0){
            while(i >= 0){
                if(s[i] == '#'){
                    backs++;
                    i--;
                }
                else if(backs > 0){
                    backs--;
                    i--;
                }
                else break;
            }

            while(j >= 0){
                if(t[j] == '#'){
                    backt++;
                    j--;
                }
                else if(backt > 0){
                    backt--;
                    j--;
                }
                else break;
            }
            
            char sChar = (i >= 0) ? s[i] : '\0';  // Use '\0' if out of bounds
            char tChar = (j >= 0) ? t[j] : '\0';  // Use '\0' if out of bounds

            if (sChar != tChar) return false;  // Mismatch found

            i--;
            j--;
        }

        return true;
    }
};