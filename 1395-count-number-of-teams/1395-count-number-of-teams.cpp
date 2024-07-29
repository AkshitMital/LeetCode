class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int teams = 0;
        for(int i = 1; i < n-1; i++){
            int LeftSmall = 0;
            int LeftBig = 0;
            int RightBig = 0;
            int RightSmall = 0;

            for(int j = 0; j < i; j++){
                if(rating[i] > rating[j]) LeftSmall++;
                if(rating[i] < rating[j]) LeftBig++;
            }

            for(int j = i+1; j < n; j++){
                if(rating[i] > rating[j]) RightSmall++;
                if(rating[i] < rating[j]) RightBig++;
            }

            teams += ((LeftSmall*RightBig) + (LeftBig*RightSmall));
        }

        return teams;
    }
};