
#include <queue>

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
    std::queue<TreeNode*> q;
    TreeNode *node, *n1, *n2;
    int found;
    
    bool isCousins(TreeNode* root, int x, int y) {
        q.push(root->left);
        q.push(root->right);
        
        while (!q.empty()) {
            found = 0;

            for (int i = q.size(); i > 0; i--) {
                node = q.front();
                q.pop();
                
                if (node != NULL) {
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            
            for (int i = q.size()/2; i > 0; i--) {
                n1 = q.front();
                q.pop();
                n2 = q.front();
                q.pop();
                q.push(n1);
                q.push(n2);
                
                if (n1 != NULL and n2 != NULL) {
                    if (n1->val == x or n1->val == y) {
                        found += 1;
                    }
                    else if (n2->val == x or n2->val == y) {
                        found += 1;
                    }
                }
                else if (n1 != NULL) {
                    if (n1->val == x or n1->val == y) {
                        found += 1;
                    }
                }
                else if (n2 != NULL) {
                    if (n2->val == x or n2->val == y) {
                        found += 1;
                    }
                }
            }
            
            if (found == 2) {
                return true;
            }
        }

        return false;
    }
};

