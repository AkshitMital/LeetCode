class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();
        vector<vector<int>> matrix(26, vector<int>(n+1, 0));

        char prevChar = s[0];
        int len = 0;

        for(int i = 0; i < n; i++){
            char currChar = s[i];

            if(currChar == prevChar){
                len += 1;
                matrix[currChar - 'a'][len] += 1;
            }else{
                len = 1;
                matrix[currChar - 'a'][len] += 1;
                prevChar = currChar;
            }
        }

        int res = 0;
        for(int i = 0; i < 26; i++){
            int cumSum = 0;
            for(int j = n; j >= 1; j--){
                cumSum += matrix[i][j];
                if(cumSum >= 3) {
                    res = max(res, j);
                    break;
                }
            }
        }


        return (res == 0) ? -1 : res;
    }
};