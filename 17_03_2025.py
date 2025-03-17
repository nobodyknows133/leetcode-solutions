class Solution:
    def divideArray(self, nums: List[int]) -> bool:
        f = Counter(nums)
        for k,v in f.items():
            if v%2==1:
                return False
        return True
