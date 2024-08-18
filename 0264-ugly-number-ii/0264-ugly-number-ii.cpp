class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> arr(n+1);
        int i2 = 1, i3 = 1, i5 = 1;
        arr[1] = 1;

        for(int i = 2; i <= n; i++){
            int i2UglyNumber = arr[i2] * 2;
            int i3UglyNumber = arr[i3] * 3;
            int i5UglyNumber = arr[i5] * 5;
            int minUglyNumber = min({i2UglyNumber, i3UglyNumber, i5UglyNumber});

            arr[i] = minUglyNumber;

            if(minUglyNumber == i2UglyNumber) i2++;
            if(minUglyNumber == i3UglyNumber) i3++;
            if(minUglyNumber == i5UglyNumber) i5++;
        }

        return arr[n];
    }
};