class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        set<int> integers;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    if(i == j || j == k || i == k) continue;

                    int integer = (digits[i] * 100) + (digits[j] * 10) + digits[k];
                    if(integer >= 100 && integer%2 == 0) integers.insert(integer);
                }
            }
        }

        vector<int> res;
        for(auto& integer : integers) res.push_back(integer);

        return res;
    }
};