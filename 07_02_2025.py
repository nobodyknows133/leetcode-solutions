class Solution:
    def queryResults(self, limit: int, queries: List[List[int]]) -> List[int]:
        mp = {} # color->freq
        mpp = {} # ball -> color
        res = []
        cnt = 0
        for q in queries:
            ind,c = q
            if ind in mpp: # ball already has color
                currCol = mpp[ind]
                currCnt = mp[currCol]
                if currCnt == 1:
                    cnt-=1
                mp[currCol]-=1
                mpp[ind]=c
                if not c in mp or mp[c]==0:
                    cnt+=1
                mp[c]=mp.get(c,0)+1
                res.append(cnt)
            else:
                mpp[ind]=c
                if not c in mp or mp[c]==0:
                    cnt+=1
                mp[c]=mp.get(c,0)+1
                res.append(cnt)
        
        return res



            

        
