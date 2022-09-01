# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:

        def dfs(node, mxv):
            if not node:
                return 0

            res = 1 if node.val >= mxv else 0

            mxv = max(node.val, mxv)

            res += dfs(node.left, mxv)
            res += dfs(node.right, mxv)
            return res

        return dfs(root, root.val)
