from sortedcontainers import SortedList
class Solution:
    def maximumSum(self, nums: List[int]) -> int:
        n = len(nums)
        mp = defaultdict(SortedList) # sumOfDigits -> poss nums[i]
        def getSum(num):
            sl=list(str(num))
            ss = 0
            for c in sl:
                ss+=int(c)

            return ss

        res = -1
        for i in range(n):
            sumOfDigits = getSum(nums[i])
            mp[sumOfDigits].add(nums[i])
            # print(mp)
            if len(mp[sumOfDigits])>=2:
                res = max(res,mp[sumOfDigits][-1]+mp[sumOfDigits][-2])

        return res







        
