class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<pair<double, int>> pq;
        for(int i = 0; i < n; i++) {
            double currPR = (double)classes[i][0]/classes[i][1];
            double newPR = (double)(classes[i][0]+1)/(classes[i][1]+1);
            double delta = (newPR - currPR);

            pq.push({delta, i});
        }

        while(extraStudents--) {
            auto curr = pq.top();
            pq.pop();

            double delta = curr.first;
            int idx = curr.second;

            classes[idx][0]++;
            classes[idx][1]++;

            double currPR = (double)classes[idx][0]/classes[idx][1];
            double newPR = (double)(classes[idx][0]+1)/(classes[idx][1]+1);;
            delta = (newPR - currPR);

            pq.push({delta, idx});
        }

        double sumDelta = 0.0;
        for(int i = 0; i < n; i++) sumDelta += (double)classes[i][0] / classes[i][1];

        return sumDelta / n;
    }
};