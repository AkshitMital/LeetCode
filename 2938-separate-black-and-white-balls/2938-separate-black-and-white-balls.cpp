class Solution {
public:
    long long minimumSteps(string s) {
        long long steps = 0, blackBalls = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '0') steps += blackBalls;
            else blackBalls++;
        }

        return steps;
    }
};