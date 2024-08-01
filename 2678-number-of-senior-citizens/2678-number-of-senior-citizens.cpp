class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;

        for(int i = 0; i < details.size(); i++){
            string temp = details[i].substr(11,2);
            int num = stoi(temp);
            if(num > 60) ans++;
        }

        return ans;
    }
};