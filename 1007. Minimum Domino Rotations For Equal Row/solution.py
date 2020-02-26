from collections import Counter
class Solution:
    def minDominoRotations(self, A: List[int], B: List[int]) -> int:
        a_counter = Counter(A)
        b_counter = Counter(B)
        common_cnt = dict()
        for i in range(len(A)):
            if A[i] == B[i]:
                cnum = A[i]
                common_cnt[cnum] = common_cnt.get(cnum,0) + 1
                
        max_cnt_num = None
        max_cnt = 0
        
        nums = set(A)
        nums |= set(B)
        for n in nums:
            a_cnt = a_counter[n]
            b_cnt = b_counter[n]
            if a_cnt + b_cnt - common_cnt.get(n,0) >= len(A):
                if a_cnt > max_cnt or b_cnt > max_cnt:
                    max_cnt_num = n
                    max_cnt = max(a_cnt, b_cnt)
        if max_cnt_num is None:
            return -1
        return len(A) - max_cnt
