class Solution(object):
    def hammingWeight(self, n):
        return ("{:032b}".format(n)).count('1')
