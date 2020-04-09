
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector>

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        std::vector<TreeNode*> acc;
        int ll_sum = 0;

        if (root != NULL)
            acc.push_back(root);
        
        while(acc.size() > 0) {
            TreeNode* n = acc.back();
            acc.pop_back();
            TreeNode* l = n->left;
            TreeNode* r = n->right;
                
            if (l != NULL) {
                if (l->left == NULL && l->right == NULL)
                    ll_sum += l->val;
                else
                    acc.push_back(l);
            }

            if (r != NULL) {
                if (r->left != NULL || r->right != NULL)
                    acc.push_back(r);
            }
        }

        return ll_sum;        
    }
};
