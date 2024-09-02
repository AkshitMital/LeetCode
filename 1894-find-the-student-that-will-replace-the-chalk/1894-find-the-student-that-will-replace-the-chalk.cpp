class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size(), i;
        long long sum = 0;
        for(auto it : chalk) sum += it;
        if(k < sum){
            for(i = 0; i <= n; i++){
                if(k < chalk[i]) break;
                k -= chalk[i];
            }
        }
        else if(k == sum) return 0;
        else{
            k %= sum;
            for(i = 0; i <= n; i++){
                if(k < chalk[i]) break;
                k -= chalk[i];
            }
        }

        return i;
    }
};