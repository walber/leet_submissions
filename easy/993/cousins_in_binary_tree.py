
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
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
