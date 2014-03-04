# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return nothing, do it in place
    def flatten(self, root):
        def _flatten(root,tail):
            if root is None:
                return tail
            root.right = _flatten(root.left, _flatten(root.right,tail))
            root.left = None
            return root
        _flatten(root,None)
            
            