class Solution {
public:
    int trap(vector<int>& height) {
        // Better Approach
        // int n = height.size();
        // if (n <= 2) return 0;
        // vector<int> leftMax(n, 0);
        // vector<int> rightMax(n, 0);
        
        // leftMax[0] = height[0];
        // for (int i = 1; i < n; i++) {
        //     leftMax[i] = max(leftMax[i - 1], height[i]);
        // }
        
        // rightMax[n - 1] = height[n - 1];
        // for (int i = n - 2; i >= 0; i--) {
        //     rightMax[i] = max(rightMax[i + 1], height[i]);
        // }
        
        // int trappedWater = 0;
        // for (int i = 0; i < n; i++) {
        //     trappedWater += min(leftMax[i], rightMax[i]) - height[i];
        // }
        
        // return trappedWater;

        // Most Optimal Approach
        int n = height.size();
        int l = 0, r = n-1, leftmax = 0, rightmax = 0, ans = 0;

        while(l<=r){
            if(height[l] <= height[r]){
                if(height[l] >= leftmax) leftmax = height[l];
                else (ans += (leftmax - height[l]));
                l++;
            }else{
                if(height[r] >= rightmax) rightmax = height[r];
                else (ans += (rightmax - height[r]));
                r--;
            }
        }

        return ans;
    }
};