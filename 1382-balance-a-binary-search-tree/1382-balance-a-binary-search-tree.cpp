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
    void findSortedArray(TreeNode* root, vector<int>& vec){
        if(!root) return;

        findSortedArray(root->left, vec);
        vec.push_back(root->val);
        findSortedArray(root->right, vec);
    }

    TreeNode* solve(int l, int r, vector<int> vec){
        if(l > r) return NULL;
        int mid = l + (r-l)/2;
        TreeNode* root = new TreeNode(vec[mid]);
        root->left = solve(l, mid-1, vec);
        root->right = solve(mid+1, r, vec);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        findSortedArray(root, inorder);
        return solve(0, inorder.size()-1, inorder);
    }
};