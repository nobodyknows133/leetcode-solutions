class Solution:
    def shiftingLetters(self, s: str, shifts: List[List[int]]) -> str:
        # calculate for each index offset and store
        offsets = [0 for _ in range(len(s)+1)]
        res = []
        for c in s:
            res.append(c)
        for st,e,dir in shifts:
            if dir == 1:
                # increase by 1 [st,e]
                offsets[st]+=1
                offsets[e+1]+=-1
            else:
                # decrease by 1[st,e]
                offsets[st]-=1
                offsets[e+1]+=1


        def findLetterToReplace(c,offset):
            return chr(ord("a") + (ord(c)-ord("a")+offset)%26)
        
        for i in range(len(s)):
            offsets[i]=(offsets[i] + (0 if i == 0 else offsets[i-1]))
            res[i]=findLetterToReplace(res[i], offsets[i])
            

        return "".join(res)

        
