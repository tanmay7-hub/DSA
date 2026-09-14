/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int , vector<TreeNode*>> dp;
    vector<TreeNode*> solve(int n) {
        vector<TreeNode*> ans;
        if(n == 1){
            TreeNode* dummy = new TreeNode(0);
            return {dummy};
        }
        if( n % 2 == 0){
            return ans;
        }

        if(dp.find(n) != dp.end())return dp[n];
      for(int i = 1 ; i < n ; i += 2 ){
         
         vector<TreeNode*> leftTree  = solve(i);
         vector<TreeNode*> rightTree = solve(n - i -1);

         for(int i = 0 ; i < leftTree.size() ; i++ ){
            for(int k = 0 ; k < rightTree.size() ; k++ ){

                TreeNode* root = new TreeNode(0);
                root->left  = leftTree[i];
                root->right = rightTree[k];
                ans.push_back(root);
            }
         }

      }
       return dp[n] = ans;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n % 2  == 0)return {};
        if(n == 1){
            TreeNode* root = new TreeNode(0);
            return {root};
        }

        return solve(n);
     }
};