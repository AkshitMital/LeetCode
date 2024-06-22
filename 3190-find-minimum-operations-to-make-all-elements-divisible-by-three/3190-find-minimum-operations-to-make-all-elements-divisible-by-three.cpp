class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int operations = 0;

        for (auto num : nums) {
            if (num % 3 == 1 || num % 3 == 2) operations ++;
        }

        return operations;
    }
};