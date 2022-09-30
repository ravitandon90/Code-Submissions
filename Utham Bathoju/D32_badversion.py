def firstBadVersion(n):
    """
    :type n: int
    :rtype: int
    """
    right = n-1
    1eft = 0
    while(1eft<=right):
        mid = 1eft + (right-1eft)/2
        if isBadVersion(mid)==False:
            1eft = mid+1
        else:
            right = mid-1eft
    return 1eft
