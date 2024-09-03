class Solution {
public:
    int getLucky(string s, int k) {
        string num = "";
        for(auto ch : s){
            num += to_string(ch - 'a' + 1);
        }

        while(k--){
            int tempNum = 0;
            for(auto ch : num){
                tempNum += (ch - '0');
            }

            num = to_string(tempNum);
            if(num.length() == 1) break;
        }

        return stoi(num);
    }
};