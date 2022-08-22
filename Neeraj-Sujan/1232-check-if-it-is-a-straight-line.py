from typing import *

class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        if(len(coordinates) == 2):
            return True
        
        coordinates = sorted(coordinates, key=lambda x: x[0])
        
        
        numerator = coordinates[1][1] - coordinates[0][1]
        denominator = coordinates[1][0] - coordinates[0][0]
        
        for i in range(0, len(coordinates)-1):
            p, q = coordinates[i][0], coordinates[i][1]
            r, s = coordinates[i+1][0], coordinates[i+1][1]
            
            if (numerator * (r-p) != (denominator * (s-q))):
                return False
           
        return True


if __name__ == "__main__":
    coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
    soln = Solution()

    res = soln.checkStraightLine(coordinates=coordinates)
    print(res)