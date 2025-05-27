class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num2 = 0;
        for(int i = m; i <= n; i += m) num2 += i;
        return (n * (n + 1) / 2) - (2*num2);
    }
};

// num1 + num2 = sum
// num1 = sum - num2;
// num1 - num2 = sum - 2 * num2;