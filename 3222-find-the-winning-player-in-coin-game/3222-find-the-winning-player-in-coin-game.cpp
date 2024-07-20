class Solution {
public:
    string losingPlayer(int x, int y) {
        int turn;
        for (turn = 1; x >= 1 && y >= 4; turn++) {
            x -= 1;
            y -= 4;
        }
        return (turn % 2 == 0) ? "Alice" : "Bob";
    }
};