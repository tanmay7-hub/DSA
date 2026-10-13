class Solution {
public:
    vector<vector<vector<TreeNode*>>> memo;
    vector<TreeNode*> helper(int st , int end){
        vector<TreeNode*> ans;

        if(st > end){
            ans.push_back(NULL);
            return ans;
        }
        if(!memo[st][end].empty())return memo[st][end];
        for(int i = st ; i <= end ; i++ ){
            
            TreeNode* root = new TreeNode(i);

            vector<TreeNode*> leftTree = helper(st , i - 1);
            vector<TreeNode*> rightTree = helper(i + 1 , end);
            for(auto lt : leftTree){
                for(auto rt : rightTree){

                    TreeNode* root = new TreeNode(i);
                    root->left = lt;
                    root->right = rt;
                    ans.push_back(root);
                }
            }
        }

        return memo[st][end] = ans;      
    }
    vector<TreeNode*> generateTrees(int n) {
        memo.clear();     
        memo = vector<vector<vector<TreeNode*>>>(n + 1, vector<vector<TreeNode*>>(n + 1));
        vector<TreeNode*> ans = helper(1 , n);
        return ans;
    }
};