class Solution {
private:
    int solve(int num, vector<int>& mapping){

        if(num < 10) return mapping[num];

        int mappednum = 0;
        int placevalue = 1;

        while(num){
            int lastDigit = num % 10;
            int mappedDigit = mapping[lastDigit];

            mappednum += (placevalue * mappedDigit);

            placevalue *= 10;
            num /= 10;
        }

        return mappednum;
    }
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> vec;

        for(int i = 0; i < n; i++){
            int mappednum = solve(nums[i], mapping);
            vec.push_back({mappednum, i});
        }

        sort(vec.begin(), vec.end());
        vector<int> res;

        for(auto& p : vec){
            int ogind = p.second;
            res.push_back(nums[ogind]);
        }

        return res;
    }
};