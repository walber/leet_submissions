# 513. Find Bottom Left Tree Value

#### Given a binary tree, find the leftmost value in the last row of the tree.

### Example 1:
```
Input:

    2
   / \
  1   3

Output:
1
```
### Example 2:
```
Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7
```
```
Note: You may assume the tree (i.e., the given root node) is not NULL.
```

## My Solutions:

### CPP:
```cpp
#include <utility>

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
```
### Python:
```python
class Solution:
    def findBottomLeftValue(self, root: TreeNode) -> int:
        
        acc = []
        acc.append((0, root))
        selected = (0, root.val)
        
        while len(acc) > 0:
            row, node = acc.pop()
            
            if node.right is not None:
                acc.append((row + 1, node.right))

            if node.left is not None:
                acc.append((row + 1, node.left))
            else:
                if row > selected[0]:
                    selected = (row, node.val)
        
        return selected[1]
```
