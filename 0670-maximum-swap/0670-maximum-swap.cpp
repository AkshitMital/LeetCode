class Solution {
public:
    int maximumSwap(int num) {
        string number = to_string(num);
        int n = number.size();
        if(n == 0 || n == 1) return num;
        vector<int> rightMax(n,-1);
        rightMax[n-1] = n-1;
        for(int i = n-2; i >= 0; i--){
            if(number[i] > number[rightMax[i+1]]) rightMax[i] = i;
            else rightMax[i] = rightMax[i+1];
        }

        for(int i = 0; i < n; i++){
            if(number[i] < number[rightMax[i]]){
                swap(number[i], number[rightMax[i]]);
                break;
            }
        }

        return stoi(number);
    }
};