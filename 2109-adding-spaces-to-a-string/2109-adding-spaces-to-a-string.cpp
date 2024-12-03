class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int SpaceIdx = 0, ch = 0;
        string ans;
        while(ch < s.length()){
            if(SpaceIdx == spaces.size()) break;
            string word = "";
            int SIdx = spaces[SpaceIdx];
            while(ch < s.length() && ch < SIdx){
                word += s[ch];
                ch++;
            }
            SpaceIdx++;
            ans += (word + " ");
        }
        
        string word = s.substr(spaces[SpaceIdx-1], s.length() - spaces[SpaceIdx-1] + 1);

        ans += word;
        return ans;
    }
};