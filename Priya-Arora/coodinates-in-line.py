class Solution:
    @staticmethod
    def compute(k: int, coordinates: List[List[int]], num: float, den: float) -> bool:
        i,j=0,1

        if (coordinates[k][j]-coordinates[k+1][j]) * den == (coordinates[k][i]-coordinates[k+1][i])* num:
            return True
        else:
            return False
        
    
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        """
        Check if coordinates are in a same line
        """
        if len(coordinates) <=2:
            return True
        
        flag=True
        
        ele1 = coordinates[0]
        ele2 = coordinates[1]
         
        i, j, k = 0, 1, 1
        num = (ele2[j]-ele1[j])
        den = (ele2[i]-ele1[i])
        
        while k < len(coordinates[1:]):
            if not self.compute(k, coordinates, num, den):
                flag=False
                break
            k=k+1
            
        if flag:
            return True
        return False
