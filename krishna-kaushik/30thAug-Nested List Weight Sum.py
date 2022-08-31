# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
# class NestedInteger(object):
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
#        """
#
#    def getInteger(self):
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        :rtype int
#        """
#
#    def getList(self):
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        :rtype List[NestedInteger]
#        """

class Solution(object):
    def depthSum(self, nestedList, current_level=1):

        #  if the element is integer, we sum up. If element is list, we use dfs to get into new depth and go through the new list again. 
        # The depth starts from 1.
        #  can add parameter current_level directly in the original function and recursively calling it for list element( DFS-recursive )


        result = 0

        for element in nestedList:
            if element.isInteger():
                result += current_level * element.getInteger()
            else:
                result += self.depthSum(element.getList(), current_level=current_level + 1)

        return result