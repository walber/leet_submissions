
#include <utility>

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
public:
    int findBottomLeftValue(TreeNode* root) {
        
        vector<std::pair<int,TreeNode*>> acc;
        std::pair<int,int> selected;
        
        acc.push_back(std::make_pair(0, root));
        selected = std::make_pair(0, root->val);
        
        while (acc.size() > 0) {
            std::pair<int,TreeNode*> p = acc.back();
            acc.pop_back();
            
            int row = p.first;
            TreeNode * node = p.second;
            TreeNode* left = node->left;
            TreeNode* right = node->right;

            if (right != NULL) {
                acc.push_back(std::make_pair(row + 1, right));
            }
            
            if (left != NULL) {
                acc.push_back(std::make_pair(row + 1, left));
            }
            else {
                if (row > selected.first) {
                    selected = std::make_pair(row, node->val);
                }
            }
        }       
            
        return selected.second;
    }
};
