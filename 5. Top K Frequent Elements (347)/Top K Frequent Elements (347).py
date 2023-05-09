class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = {}
        topK = [[] for i in range(len(nums))]
        res = []

        for n in nums:
            freq[n] = 1+freq.get(n,0)

        for n, count in freq.items():
            topK[count-1].append(n)
        
        for i in range(len(nums)-1, -1, -1):
            if not k:
                break
            k = k - len(topK[i])
            res = res + topK[i]
        
        return res