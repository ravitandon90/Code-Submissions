"""
The idea is to construct a segment tree. The left and right endpoints of an interval as well as its total_sum are stored in each node.
Each internal node will store the sum of the leaves beneath it, and all of the leaves will store the array's contents.

It takes O(n) time to build the tree. Both queries and updates are O (log n).
"""

#Segment tree node
class Node(object):
    def __init__(self, begin, end):
        self.begin = begin
        self.end = end
        self.total_sum = 0
        self.left = None
        self.right = None
        

class NumArray(object):
    def __init__(self, nums):
        #helper function to build the tree from the input array
        def createTree(nums, l, r):
            
            #base case
            if l > r:
                return None
                
            #leaf node
            if l == r:
                n = Node(l, r)
                n.total_sum = nums[l]
                return n
            
            mid = (l + r) // 2
            
            root = Node(l, r)
            
            #recursively build the Segment tree
            root.left = createTree(nums, l, mid)
            root.right = createTree(nums, mid+1, r)
            
            #total_sum stores the sum of all leaves under root i.e. those elements lying between (begin, end)
            root.total_sum = root.left.total_sum + root.right.total_sum
                
            return root
        
        self.root = createTree(nums, 0, len(nums)-1)
            
    def update(self, i, val):

        #Helper function to update a value
        def updateVal(root, i, val):
            
            #Base case. A leaf will be updated with the actual value. After that, the total sum is propagated upward
            if root.begin == root.end:
                root.total_sum = val
                return val
        
            mid = (root.begin + root.end) // 2
            
            #A leaf is in the left subtree if the index is lower than the midpoint.
            if i <= mid:
                updateVal(root.left, i, val)
                
            #Otherwise, the right subtree
            else:
                updateVal(root.right, i, val)
            
            #Propogate the changes after recursive call returns
            root.total_sum = root.left.total_sum + root.right.total_sum
            
            return root.total_sum
        
        return updateVal(self.root, i, val)

    def sumRange(self, i, j):

        #Helper function to calculate range sum
        def rangeSum(root, i, j):
            
            #If the range exactly matches the root, we already have the sum
            if root.begin == i and root.end == j:
                return root.total_sum
            
            mid = (root.begin + root.end) // 2
            
            #The entire interval lies in the left subtree if the end of the range is less than the midpoint.
            if j <= mid:
                return rangeSum(root.left, i, j)
            
            #If begin of the interval is greater than mid, the entire interval is located in the right subtree.
            elif i >= mid + 1:
                return rangeSum(root.right, i, j)
            
            #Otherwise, the interval is split. So we recursively calculate the sum,by splitting the interval
            else:
                return rangeSum(root.left, i, mid) + rangeSum(root.right, mid+1, j)
        
        return rangeSum(self.root, i, j)