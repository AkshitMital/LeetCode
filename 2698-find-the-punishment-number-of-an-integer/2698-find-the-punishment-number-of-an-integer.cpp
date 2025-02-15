class Solution {
private:
    bool check(int sq, int currSum, int num) {
        if(sq == 0) {
            return (currSum == num);
        }

        return check(sq / 10, currSum + (sq % 10), num) ||
        check(sq / 100, currSum + (sq % 100), num) ||
        check(sq / 1000, currSum + (sq % 1000), num) ||
        check(sq / 10000, currSum + (sq % 10000), num);
    }
public:
    int punishmentNumber(int n) {
        int punish = 0;

        for(int num = 1; num <= n; num++) {
            int sq = num * num;

            if(check(sq, 0, num)) {
                punish += sq;
            }
        }

        return punish;
    }
};