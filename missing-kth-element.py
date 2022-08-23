class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        """
        Finding kth missing element in a stricktly sorted array
        Applying binary search O(logN) by comparing index of mid
        with its value
        """
        low = 0
        high = len(arr)
        
        while low < high:
            mid = math.floor(low + (high-low)/2)
            if ((arr[mid] - (mid+1)) < k):
                low = mid + 1
            else:
                high = mid;
        return low+k;
        
                
        
                
        
            
        
