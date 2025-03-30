class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int> result;
        vector<int> mpp(26, -1);
        for(int i = 0; i < n; i++) {
            mpp[s[i] - 'a'] = i;
        }

        int start = 0, end = 0, j = 0;
        while(j < n) {
            end = max(end, mpp[s[j] - 'a']);
            if(j == end) {
                result.push_back(end - start + 1);
                start = end + 1;
            }
            j++;
        }

        return result;
    }
};