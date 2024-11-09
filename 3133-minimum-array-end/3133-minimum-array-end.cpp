class Solution {
public:
    long long minEnd(int n, int x) {
        if(n == 1) return x;
        long long ans = x, temp = x;
        while(n != 0){
            if((x & temp) == x){
                ans = temp;
                n--;
            }

            temp++;
        }

        return ans;
    }
};