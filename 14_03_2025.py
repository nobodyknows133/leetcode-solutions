class Solution:
    def maximumCandies(self, candies: List[int], k: int) -> int:
        res = 0
        l = 1
        r = max(candies)

        def canDistribute(candies,k,mid):
            cnt = 0
            for x in candies:
                cnt+=(x//mid)
            return cnt>=k



        while l<=r:
            mid = l + (r-l)//2
            if canDistribute(candies,k,mid):
                res = max(res,mid)
                l = mid + 1
            else:
                r = mid - 1

        return res
        
