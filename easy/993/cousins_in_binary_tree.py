
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        p_stack = [root.left, root.right]
        c_stack = []

        while len(p_stack) > 0:
            found = 0

            while len(p_stack) > 0:
                node = p_stack.pop()
                
                if node:
                    c_stack.append(node.left)
                    c_stack.append(node.right)

            while len(c_stack) > 0:
                n1 = c_stack.pop()
                n2 = c_stack.pop()
                p_stack.append(n1)
                p_stack.append(n2)

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
        
