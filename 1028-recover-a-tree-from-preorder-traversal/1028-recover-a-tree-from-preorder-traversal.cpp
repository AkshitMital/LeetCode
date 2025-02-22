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
    TreeNode* solve(string& s, int& i, int depth, int n) {
        if(i >= n) return NULL;

        int j = i;
        while(j < n && s[j] == '-') j++;

        int dash = j - i;

        if(dash != depth) return NULL;

        i += dash;

        int value = 0;
        while(i < n && isdigit(s[i])) {
            value = (value * 10) + (s[i] - '0');
            i++;
        }

        TreeNode* root = new TreeNode(value);

        root->left  = solve(s, i, depth + 1, n);
        root->right = solve(s, i, depth + 1, n);

        return root;
    }
public:
    TreeNode* recoverFromPreorder(string traversal) {
        int i = 0;
        return solve(traversal, i, 0, traversal.length());
    }
};