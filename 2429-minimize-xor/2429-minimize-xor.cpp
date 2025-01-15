class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int x = num1;

        int reqBits = __builtin_popcount(num2);
        int currBits = __builtin_popcount(x);

        int bit = 0;
        if(currBits < reqBits) {
            while(currBits < reqBits) {
                if(!(x & (1 << bit))){
                    x = (x | (1 << bit));
                    currBits++;    
                }
                bit++;
            }
        }
        else if(currBits > reqBits) {
            while(currBits > reqBits) {
                if((x & (1 << bit))){
                    x = (x & ~(1 << bit));
                    currBits--;
                }
                bit++;
            }
        }

        return x;
    }
};