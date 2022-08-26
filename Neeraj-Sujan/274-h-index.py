class Solution:
    def hIndex(self, citations: List[int]) -> int:
        low = 0
        high = len(citations)-1
        n = len(citations)
        citations = sorted(citations)
        while(low <=high):
            mid = low + (high-low)//2
            if(citations[mid] == (n-mid)):
                return citations[mid]
            elif citations[mid] > (n-mid):
                high = mid-1
            else:
                low = mid+1
        return n-low