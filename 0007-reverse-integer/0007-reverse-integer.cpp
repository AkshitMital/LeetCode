class Solution {
public:
    int reverse(int x) {
        int n = abs(x);
        long long temp = 0;
        while(n){
            int digit = n%10;
            temp = temp * 10 + digit;
            if(temp > INT_MAX) return 0;
            n /= 10;
        }

        return (x < 0) ? temp * -1 : temp;
    }
};