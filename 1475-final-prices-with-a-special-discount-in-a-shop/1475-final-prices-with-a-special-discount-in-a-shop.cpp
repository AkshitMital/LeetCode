class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        st.push(0);
        for(int i = prices.size() - 1; i >=0; i-- ){
            while(prices[i] < st.top()){
                st.pop();
            }
            
            int small = st.top();
            
            st.push(prices[i]);
            
            prices[i] -= small;
        }
        return prices;
    }
};