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
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int level = 0;

        while(!q.empty()){
            int n = q.size();

            vector<TreeNode*> levelNodes;
            while(n--){
                TreeNode* temp = q.front();
                q.pop();
                levelNodes.push_back(temp);

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

            if(level % 2 == 1){
                int l = 0, r = levelNodes.size() - 1;
                while(l <= r){
                    int tempVal = levelNodes[l]->val;
                    levelNodes[l]->val = levelNodes[r]->val;
                    levelNodes[r]->val = tempVal;
                    l++; r--;
                }
            }

            level++;
        }

        return root;
    }
};