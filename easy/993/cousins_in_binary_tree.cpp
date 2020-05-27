
#include <vector>

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
    std::vector<TreeNode*> p_stack;
    std::vector<TreeNode*> c_stack;
    TreeNode *node, *n1, *n2;
    int found;
    
    bool isCousins(TreeNode* root, int x, int y) {
        p_stack.push_back(root->left);
        p_stack.push_back(root->right);
        
        while (p_stack.size() > 0) {
            found = 0;

            while (p_stack.size() > 0) {
                node = p_stack.back();
                p_stack.pop_back();
                
                if (node != NULL) {
                    c_stack.push_back(node->left);
                    c_stack.push_back(node->right);
                }
            }
            
            while (c_stack.size() > 0) {
                n1 = c_stack.back();
                c_stack.pop_back();
                n2 = c_stack.back();
                c_stack.pop_back();
                p_stack.push_back(n1);
                p_stack.push_back(n2);
                
                if (n1 != NULL and n2 != NULL) {
                    if (n1->val == x || n1->val == y) {
                        found += 1;
                    }
                    else if (n2->val == x || n2->val == y) {
                        found += 1;
                    }
                }
                else if (n1 != NULL) {
                    if (n1->val == x || n1->val == y) {
                        found += 1;
                    }
                }
                else if (n2 != NULL) {
                    if (n2->val == x || n2->val == y) {
                        found += 1;
                    }
                }
            }
            
            if (found == 2) {
                return true;
            }
        }
        
        p_stack.clear();
        c_stack.clear();
        return false;
    }
};
