import sys
class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        """
        This is finding the maximum no of boxes that can be fit in the given truck
        """
        if truckSize <=0:
            return sys.minsize
        
        # Sort as per the no of units as this is the value we are gonna maximize
        result = sorted(boxTypes, key=lambda t: t[1], reverse=True)
        
        sz=0
        maxUnits=0
        for noBoxes, unitsPerBox in result:
            if sz < truckSize and (truckSize - sz) < noBoxes:
                temp = (truckSize - sz)
                sz = sz + (truckSize - sz)
                maxUnits = maxUnits + (temp* unitsPerBox)
            elif sz < truckSize and (truckSize - sz) >= noBoxes:
                sz = sz + noBoxes
                maxUnits = maxUnits + noBoxes * unitsPerBox
        return maxUnits

                
            
            
        
