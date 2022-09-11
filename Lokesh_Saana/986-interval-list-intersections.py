# https://leetcode.com/problems/interval-list-intersections/

class Solution:
    def intervalIntersection(self, firstList: List[List[int]], secondList: List[List[int]]) -> List[List[int]]:
        i = j = 0
        result = []
        while i < len(firstList) and j < len(secondList):
            a_left, a_right = firstList[i]
            b_left, b_right = secondList[j]
            if a_left <= b_right and b_left <= a_right:
                result.append([max(a_left, b_left), min(a_right, b_right)])
            if a_right <= b_right:
                i += 1
            else:
                j += 1
        return result
