class Solution {
private:
    string getBinary(int n){
        if(n == 1) return "0";

        string left = getBinary(n-1);
        string mid = "1";
        string right = left;
        for(int i = 0; i < right.size(); i++){
            if(right[i] == '0') right[i] = '1';
            else right[i] = '0';
        }
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
public:
    char findKthBit(int n, int k) {
        string sn = getBinary(n);
        // int kth = (k << 1) & snINT;
        // return (kth == 0) ? '0' : '1';
        return sn[k-1];
    }
};