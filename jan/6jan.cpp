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

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (root == NULL)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        int anslevel = 1;
        long long maxsum = LLONG_MIN;
        while (!q.empty()) {
            int size = q.size();
            long long sum = 0;
            FOR(i, 0, size) {
                TreeNode* curr = q.front();
                q.pop();
                sum += curr->val;
                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
            }
            if (sum > maxsum) {
                maxsum = sum;
                anslevel = level;
            }
            level++;
        }
        return anslevel;
    }
};
