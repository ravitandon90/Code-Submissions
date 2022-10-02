def firstBadVersion(n):
    """
    :type n: int
    :rtype: int
    """
    right = n-1
    left = 0
    while(left<=right):
        mid = left + (right-left)/2
        if isBadVersion(mid)==False:
            left = mid+1
        else:
            right = mid-left
    return left
