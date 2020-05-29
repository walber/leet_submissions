# 993. Cousins in Binary Tree

#### In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1. Two nodes of a binary tree are cousins if they have the same depth, but have different parents. We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree. Return true if and only if the nodes corresponding to the values x and y are cousins.

### Example 1:
```
Input: root = [1,2,3,4], x = 4, y = 3
Output: false
```
### Example 2:
```
Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
```
### Example 3:
```
Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
```
### Constraints:
* The number of nodes in the tree will be between 2 and 100.
* Each node has a unique integer value from 1 to 100.

## My Solution:

### CPP:
```cpp
#include <queue>

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

        return false;
    }
};

```
### Python 3:
```python
class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        queue = [root.left, root.right]

        while len(queue) > 0:
            found = 0

            for i in range(len(queue)):
                node = queue.pop(0)
                
                if node:
                    queue.append(node.right)
                    queue.append(node.left)

            for i in range(len(queue)//2):
                n1 = queue.pop(0)
                n2 = queue.pop(0)
                queue.append(n1)
                queue.append(n2)

                if n1 and n2:
                    if n1.val == x or n1.val == y:
                        found += 1 
                    elif n2.val == x or n2.val == y:
                        found += 1
                elif n1:
                    found += 1 if n1.val == x or n1.val == y else 0

                elif n2:
                    found += 1 if n2.val == x or n2.val == y else 0

            if found == 2:
                return True

        return False
```
