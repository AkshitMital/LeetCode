class Solution {
public:
    bool canTransform(string start, string result) {
        int s = 0, r = 0, n = start.length();

        while(s < n || r < n) {
            while (s < n && start[s] == 'X') s++;
            while (r < n && result[r] == 'X') r++;

            if ((s < n) != (r < n)) return false;

            if (s == n && r == n) return true;

            if (start[s] != result[r]) return false;

            if (start[s] == 'L' && s < r) return false;
            if (start[s] == 'R' && s > r) return false;

            s++; r++;
        }

        return true;
    }
};