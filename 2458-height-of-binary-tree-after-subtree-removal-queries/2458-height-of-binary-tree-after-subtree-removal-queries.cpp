/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int solve(TreeNode* root, int lev, vector<int>& level, vector<int>& height, vector<int>& maxLevelHeight, vector<int>& secondMaxLevelHeight){
        if(root == NULL) return 0;

        level[root->val] = lev;

        int l = solve(root->left, lev + 1, level, height, maxLevelHeight, secondMaxLevelHeight);
        int r = solve(root->right, lev + 1, level, height, maxLevelHeight, secondMaxLevelHeight);

        height[root->val] = 1 + max(l, r);

        if(maxLevelHeight[lev] < height[root->val]){
            secondMaxLevelHeight[lev] = maxLevelHeight[lev];
            maxLevelHeight[lev] = height[root->val];
        }
        else if(secondMaxLevelHeight[lev] < height[root->val]){
            secondMaxLevelHeight[lev] = height[root->val];
        }

        return height[root->val];
    }
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> level(1e5+1, 0);
        vector<int> height(1e5+1, 0);
        vector<int> maxLevelHeight(1e5+1, 0);
        vector<int> secondMaxLevelHeight(1e5+1, 0);
        vector<int> ans(queries.size(), 0);

        solve(root, 0, level, height, maxLevelHeight, secondMaxLevelHeight);

        for(int i = 0; i < queries.size(); i++){
            int query = queries[i];
            int lev = level[query];
            int maxHeight = maxLevelHeight[lev];
            int secondMaxHeight = secondMaxLevelHeight[lev];

            if(maxHeight == height[query]){
                ans[i] = lev + secondMaxHeight - 1;
            }
            else{
                ans[i] = lev + maxHeight - 1;
            }
        }

        return ans;
    }
};