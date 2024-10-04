class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int sum = 0, n = skill.size();
        unordered_map<int,int> mpp;
        for(int& s : skill){
            sum += s;
            mpp[s]++;
        }

        if((sum*2)%n != 0) return -1;
        int teams = n/2;
        int totalSkill = (sum*2)/n;

        int chem = 0;

        for(int i = 0; i < n; i++){
            int currSkill = skill[i];
            int leftSkill = totalSkill - currSkill;
            if(mpp[currSkill] == 0) continue;
            if(mpp[leftSkill] == 0) return -1;
            mpp[currSkill]--;
            mpp[leftSkill]--;
            chem += (currSkill*leftSkill);
        }

        return chem;

    }
};