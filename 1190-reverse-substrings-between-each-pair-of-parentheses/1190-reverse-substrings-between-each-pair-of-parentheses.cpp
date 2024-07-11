string shit(int & i,string s,int len){
    string b="";
    string extra="";
    int flag=0;
    while(i<len){
        if(flag==0){
            if(s[i]=='('){
                flag=1;
            }
            else if(isalpha(s[i])){
                b+=s[i];
            }
        }
        else if(flag==1){
            if(isalpha(s[i])){
                extra+=s[i];
            }
            else if(s[i]==')'){
                reverse(extra.begin(),extra.end());
                b+=extra;
                //i++;
                return b;
            }
            else if(s[i]=='('){
                //i++;
                extra+=shit(i,s,len);
                
            }
        }
        i++;
    }
    return b;
}

class Solution {
public:
    string reverseParentheses(string s) {
        string ans="";
        int len=s.size();
        int i=0;
        //ans=shit(i,s,len);
        while(i<len){
            ans+=shit(i,s,len);
        }
        return ans;
    }
};