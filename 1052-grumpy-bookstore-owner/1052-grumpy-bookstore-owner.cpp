class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int count = 0, unsatisfied = 0, max_unsatisfied = 0, satisfied = 0;
        for(int i = 0; i < grumpy.size(); i++){
            if(!grumpy[i]) satisfied += customers[i];
            if(grumpy[i]) unsatisfied += customers[i];
            count++;
            if(count == minutes){
                int prev = i - minutes + 1;
                max_unsatisfied = max(max_unsatisfied, unsatisfied);
                if(grumpy[prev]) unsatisfied -= customers[prev];
                count -= 1;
            }
        }

        return (satisfied + max_unsatisfied);
    }
};