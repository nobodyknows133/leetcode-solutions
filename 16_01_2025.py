class Solution:
    def xorAllNums(self, nums1: List[int], nums2: List[int]) -> int:
        f = {}
        l1 = len(nums1)
        l2 = len(nums2)
        for n in nums1:
            f[n]=f.get(n,0)+l2
        
        for n in nums2:
            f[n]=f.get(n,0)+l1
        
        res=0
        for k,v in f.items():
            if v%2==1:
                res^=k

        return res
        
        
