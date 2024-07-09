class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double n = customers.size();
        double consec = customers[0][0] + customers[0][1];
        double num = customers[0][1];
        for(int i = 1; i < n; i++){
            if(customers[i][0] < consec) {
                consec += customers[i][1];
                num += (consec-customers[i][0]);
            }
            else {
                consec = customers[i][0] + customers[i][1];
                num += customers[i][1];
            }
        }
        return num/n;
    }
};