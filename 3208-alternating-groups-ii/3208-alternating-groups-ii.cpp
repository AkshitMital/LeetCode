class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size() + k - 1;

        vector<int> temp = colors;
        temp.insert(temp.end(), colors.begin(), colors.end());

        int i = 0, j = 1, res = 0;
        while(j < n) {
            if(temp[j] == temp[j-1]) {
                i = j;
                j++;
                continue;
            }

            if(j - i + 1 == k) {
                res++;
                i++;
            }

            j++;
        }

        return res;
    }
};