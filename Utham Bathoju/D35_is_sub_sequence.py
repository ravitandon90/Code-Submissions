def isSubsequence(s: str, t: str) -> bool:
    length = len(s)
    index = 0;
    for ele in t:
        if index == length:
            break
        if ele == s[index]:
            index += 1
    return length == index
