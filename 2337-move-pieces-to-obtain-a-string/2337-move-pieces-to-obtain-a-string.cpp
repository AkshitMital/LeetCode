class Solution {
public:
    bool canChange(string start, string target) {
        int s = 0, t = 0, n = start.length();

        while(s < n && t < n){
            while(s < n && start[s] == '_') s++;
            while(t < n && target[t] == '_') t++;
            char Sdir = start[s];
            char Tdir = target[t];

            if(Sdir != Tdir) return false;

            if(Sdir == 'L'){
                if(s < t) return false;
            }
            else{
                if(s > t) return false;
            }

            s++; t++;
        }

        while(t < n && target[t] == '_') t++;
        if(t == n) return true;

        return true;
    }
};