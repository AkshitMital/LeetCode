// class Solution {
// private:
//     bool solve(string s1, string s2){
//         vector<string> vec1, vec2;

//         stringstream ss1(s1);
//         string token;
//         while(ss1 >> token) vec1.push_back(token);

//         stringstream ss2(s2);
//         while(ss2 >> token) vec2.push_back(token);

//         int i = 0, j = vec1.size()-1, k = 0, l = vec2.size()-1;

//         while(i < vec1.size() && k < vec2.size() && vec1[i] == vec2[k]){
//             i++;
//             k++;
//         }

//         while(j >= 0 && l >= 0 && vec1[j] == vec2[l]){
//             j--;
//             l--;
//         }

//         if(l < k) return true;

//         return false;
//     }
// public:
//     bool areSentencesSimilar(string s1, string s2) {
//         if(s1.length() > s2.length()) 
//             return solve(s1, s2);
        
//         return solve(s2, s1);
//     }
// };

class Solution {
private:
    bool solve(string s1, string s2){
        deque<string> deq1, deq2;

        stringstream ss1(s1);
        string token;
        while(ss1 >> token) deq1.push_back(token);

        stringstream ss2(s2);
        while(ss2 >> token) deq2.push_back(token);

        while(!deq2.empty() && deq1.front() == deq2.front()){
            deq1.pop_front();
            deq2.pop_front();
        }

        while(!deq2.empty() && deq1.back() == deq2.back()){
            deq1.pop_back();
            deq2.pop_back();
        }

        if(deq2.empty()) return true;

        return false;
    }
    
public:
    bool areSentencesSimilar(string s1, string s2) {
        if(s1.length() > s2.length()) 
            return solve(s1, s2);
        
        return solve(s2, s1);
    }
};