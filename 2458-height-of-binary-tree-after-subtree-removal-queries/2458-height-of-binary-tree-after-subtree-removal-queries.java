/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private int solve(TreeNode root, int lev, int[] height, int[] level, int[] levelMaxHt, int[] secLevelMaxHt){
        if(root == null) return 0;

        level[root.val] = lev;

        int l = solve(root.left, lev+1, height, level, levelMaxHt, secLevelMaxHt);
        int r = solve(root.right, lev+1, height, level, levelMaxHt, secLevelMaxHt);

        height[root.val] = 1 + Math.max(l, r);

        if(levelMaxHt[lev] < height[root.val]){
            secLevelMaxHt[lev] = levelMaxHt[lev];
            levelMaxHt[lev] = height[root.val]; 
        }
        else if(secLevelMaxHt[lev] < height[root.val]) secLevelMaxHt[lev] = height[root.val];

        return height[root.val];
    }

    public int[] treeQueries(TreeNode root, int[] queries) {
        int[] height = new int[100001];
        int[] level = new int[100001];
        int[] levelMaxHt = new int[100001];
        int[] secLevelMaxHt = new int[100001];
        int n = queries.length;
        int[] ans = new int[n];

        solve(root, 0, height, level, levelMaxHt, secLevelMaxHt);

        for(int i = 0; i < n; i++){
            int query = queries[i];
            int lev = level[query];
            int ht = height[query];
            int maxHt = levelMaxHt[lev];
            int secMaxHt = secLevelMaxHt[lev];

            if(maxHt == ht) ans[i] = lev + secMaxHt - 1;
            else ans[i] = lev + maxHt - 1;
        }

        return ans;
    }
}