
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
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
