
# Sum of Left Leaves

#### Find the sum of all left leaves in a given binary tree.

Example:
```
    3
   / \
  9  20
    /  \
   15   7
```

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

## My Solutions:

### C++:
```cpp
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
```
### Python 3:
```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        acc = list()
        ll_sum = 0

        if root is not None:
            acc.append(root)
        
        while len(acc) > 0:
            n = acc.pop()
            l_node = n.left
            r_node = n.right

            if l_node is not None:
                if l_node.left is None and l_node.right is None:
                    ll_sum += l_node.val
                else:
                    acc.append(l_node)

            if r_node is not None:
                if r_node.left is not None or r_node.right is not None:
                    acc.append(r_node)

        return ll_sum
```
