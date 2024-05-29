class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        while (s != "1") {
            if (s.back() == '0') {
                // If the last character is '0', it's even, so we can divide by 2
                s.pop_back();
            } else {
                // If the last character is '1', it's odd, so we need to add 1
                // Find the first '0' from the end to change it to '1' and set all bits after it to '0'
                int i = s.size() - 1;
                while (i >= 0 && s[i] == '1') {
                    s[i] = '0';
                    i--;
                }
                if (i >= 0) {
                    s[i] = '1';
                } else {
                    // If all bits were '1', prepend '1' to the string
                    s = '1' + s;
                }
            }
            steps++;
        }
        return steps;
    }
};
