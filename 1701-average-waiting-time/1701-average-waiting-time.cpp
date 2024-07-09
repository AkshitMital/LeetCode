class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int currentTime = 0;
        double totalWaitTime = 0.0;

        for (const auto& customer : customers) {
            int arrivalTime = customer[0];
            int cookingTime = customer[1];

            if (currentTime < arrivalTime) {
                currentTime = arrivalTime;
            }

            currentTime += cookingTime;
            totalWaitTime += (currentTime - arrivalTime);
        }

        return totalWaitTime / customers.size();
    }
};
