// class Solution {
// private:
//     string getBinary(int n){
//         if(n == 1) return "0";

//         string left = getBinary(n-1);
//         string mid = "1";
//         string right = left;
//         for(int i = 0; i < right.size(); i++){
//             if(right[i] == '0') right[i] = '1';
//             else right[i] = '0';
//         }
//         reverse(right.begin(), right.end());

//         return left + mid + right;
//     }
// public:
//     char findKthBit(int n, int k) {
//         string sn = getBinary(n);
//         return sn[k-1];
//     }
// };

class Solution {
public:
    char findKthBit(int n, int k) {
        if(n == 1 && k == 1) return '0';

        int len = (1 << n) - 1; // pow(2, n) - 1

        if(k < ceil(len/2.0)){
            return findKthBit(n-1, k);
        }
        else if(k == ceil(len/2.0)) return '1';
        else{
            char ch = findKthBit(n-1, len-k+1);
            return (ch == '0') ? '1' : '0';
        }
    }
};