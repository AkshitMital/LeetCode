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
    int countOperations(vector<int>& vec){
        vector<int> sortedVec(vec.begin(), vec.end());
        sort(sortedVec.begin(), sortedVec.end());
        unordered_map<int,int> mpp;

        for(int i = 0; i < vec.size(); i++) mpp[vec[i]] = i;

        int swaps = 0;

        for(int i = 0; i < vec.size(); i++){
            if(sortedVec[i] == vec[i]) continue;

            int currIdx = mpp[sortedVec[i]];
            mpp[vec[i]] = currIdx;

            swap(vec[currIdx], vec[i]);

            swaps++;
        }

        return swaps;
    }
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int result = 0;
        
        while(!q.empty()){
            int sz = q.size();
            vector<int> vec;

            while(sz--){
                TreeNode* node = q.front();
                q.pop();

                vec.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

            }

            result += countOperations(vec);
        }

        return result;
    }
};