class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        n = len(nums)
        mp = defaultdict(set)
        for i in range(n):
            for j in range(n):
                if nums[i]==nums[j]:
                    continue
                mp[nums[i]*nums[j]].add(tuple(sorted([nums[i],nums[j]])))

        res=0
        for k,s in mp.items():
            v = len(s)
            if v>=2:
                res+=((v*(v-1))//2)

        return res*8

                

        
