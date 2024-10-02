class Solution {
private:
    int count(long long curr, long long next, long long n){
        int countNum = 0;
        while(curr <= n){
            countNum += (next-curr);
            curr *= 10;
            next *= 10;
            next = min(next, n+1);
        }
        return countNum;
    }
public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;

        while(k){
            int steps = count(curr, curr+1, n);
            if(steps <= k){
                curr += 1;
                k -= steps;
            }else{
                curr *= 10;
                k--;
            }
        }

        return curr;
    }
};