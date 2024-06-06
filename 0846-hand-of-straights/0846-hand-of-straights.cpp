class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;
        sort(hand.begin(), hand.end());
        unordered_map<int, int> mpp;
        for(auto it : hand) mpp[it]++;

        for(int i = 0; i < hand.size(); i++){
            if(!mpp[hand[i]]) continue;
            int k = groupSize;
            int num = hand[i];
            while(k--){
                if(mpp[num]){
                    mpp[num]--;
                    num++;
                }
                else return false;
            }
        }

        return true;
    }
};