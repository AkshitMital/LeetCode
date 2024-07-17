class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.size();
        stack<unordered_map<string, int>> st;
        st.push(unordered_map<string,int>());
        int i = 0;
        while(i < n){
            if(formula[i] == '('){
                st.push(unordered_map<string,int>());
                i++;
            }
            else if(formula[i] == ')'){
                unordered_map<string,int> curr = st.top();
                st.pop();
                i++;

                string mult;
                while((i < n) && isdigit(formula[i])){
                    mult.push_back(formula[i]);
                    i++;
                }
                if(!mult.empty()){
                    int multi = stoi(mult);
                    for(auto it : curr){
                        curr[it.first] = it.second * multi;
                    }
                }

                for(auto it : curr){
                    string element = it.first;
                    int count = it.second;
                    st.top()[element] += count;
                }

            }else{
                string currElement;
                currElement.push_back(formula[i]);
                i++;
                while(i < n && isalpha(formula[i]) && islower(formula[i])){
                    currElement.push_back(formula[i]);
                    i++;
                }

                string currCount;
                while(i < n && isdigit(formula[i])){
                    currCount.push_back(formula[i]);
                    i++;
                }

                int cnt = (currCount.empty()) ? 1 : stoi(currCount);
                st.top()[currElement] += cnt;
            }
        }

        map<string, int> sortedMap(st.top().begin(), st.top().end());

        string result;

        for(auto it : sortedMap){
            result += it.first;
            if(it.second > 1) result += to_string(it.second);
        }

        return result;
    }
};