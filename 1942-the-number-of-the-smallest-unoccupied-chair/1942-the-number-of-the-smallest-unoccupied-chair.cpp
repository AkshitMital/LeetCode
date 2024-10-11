class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        set<int> freeChair;
        int targetArrivalTime = times[targetFriend][0];

        sort(times.begin(), times.end());

        int chair = 0, targetChair = 0;
        for(int i = 0; i < times.size(); i++){
            int arrival = times[i][0];
            int departure = times[i][1];

            while(!pq.empty() && pq.top().first <= arrival){
                freeChair.insert(pq.top().second);
                pq.pop();
            }

            int assignedChair = 0;
            if(freeChair.empty()){
                assignedChair = chair++;
            }else{
                assignedChair = *freeChair.begin();
                freeChair.erase(freeChair.begin());
            }

            if(arrival == targetArrivalTime) return assignedChair;

            pq.push({departure, assignedChair});
        }

        return -1;
    }
};