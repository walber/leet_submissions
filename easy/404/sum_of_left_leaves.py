
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
