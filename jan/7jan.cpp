class Solution {
public:
    long long totalSum = 0;
    long long ans = 0;
    int MOD = 1e9 + 7;

    long long getTotal(TreeNode* root){
        if(root == NULL) return 0;
        return root->val + getTotal(root->left) + getTotal(root->right);
    }

    long long dfs(TreeNode* root){
        if(root == NULL) return 0;

        long long left = dfs(root->left);
        long long right = dfs(root->right);

        long long subSum = root->val + left + right;

        ans = max(ans, subSum * (totalSum - subSum));

        return subSum;
    }

    int maxProduct(TreeNode* root) {
        totalSum = getTotal(root);
        dfs(root);
        return ans % MOD;
    }
};
