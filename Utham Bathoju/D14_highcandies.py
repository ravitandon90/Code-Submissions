class Solution:
    def kidsWithCandies(self, candies:List[int], extra_candies:int) -> List[bool]:
        bool_candies = []
        high_candy = max(candies)
        if len(candies) == 1:
            return [True]
        for candy_num in candies:
            candy_diff = high_candy - candy_num 
            if candy_diff <= extra_candies:
                bool_candies.append(True)
            else:
                bool_candies.append(False)
        return bool_candies
