class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int mask = 0;

        for(char& ch : allowed) mask |= (1 << (ch - 'a'));

        int cnt = 0;

        for(string& word : words){
            bool allCharPresent = true;

            for(char& ch : word){
                if(((mask >> (ch - 'a')) & 1) == 0){
                    allCharPresent = false;
                    break;
                }
            }

            if(allCharPresent == true) cnt++;
        }

        return cnt;
    }
};