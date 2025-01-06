class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        res = [0 for _ in range(len(boxes))]
        for i in range(len(boxes)):
            # calculate for ith box
            cnt = 0
            for j,c in enumerate(boxes):
                if c=="1":
                    cnt+=abs(j-i)
            res[i]=cnt


        return res
