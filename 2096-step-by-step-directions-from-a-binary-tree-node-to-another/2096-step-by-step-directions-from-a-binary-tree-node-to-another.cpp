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
    bool findPath(TreeNode* root, int target, string& path){
        if(!root) return false;
        if(root -> val == target) return true;

        path.push_back('L');
        if(findPath(root->left, target, path)) return true;
        path.pop_back();

        path.push_back('R');
        if(findPath(root->right, target, path)) return true;
        path.pop_back();

        return false;
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string rootToSrc = "";
        string rootToDest = "";

        findPath(root, startValue, rootToSrc);
        findPath(root, destValue, rootToDest);

        int x = 0;
        while(x < rootToSrc.length() && x < rootToDest.length() && rootToSrc[x]==rootToDest[x]) x++;


        string res = "";

        for(int i = x; i < rootToSrc.length(); i++){
            res.push_back('U');
        }

        for(int i = x; i < rootToDest.length(); i++){
            res.push_back(rootToDest[i]);
        }

        return res;
    }
};