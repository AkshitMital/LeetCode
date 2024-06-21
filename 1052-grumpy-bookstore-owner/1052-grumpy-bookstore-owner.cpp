class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int count = 0, unsatisfied = 0, maxi = 0, ans = 0;
        for(int i = 0; i < grumpy.size(); i++){
            if(!grumpy[i]) ans += customers[i];
            if(grumpy[i]) unsatisfied += customers[i];
            count++;
            if(count == minutes){
                int prev = i - minutes + 1;
                maxi = max(maxi, unsatisfied);
                if(grumpy[prev]) unsatisfied -= customers[prev];
                count -= 1;
            }
        }

        return (ans + maxi);
    }
};