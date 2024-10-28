class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        max_sum = 0
        for i in range(k):
            max_sum += nums[i]

        p1 = 0
        p2 = k
        n = len(nums)
        sumNum = max_sum
        while p2 < n:
            sumNum -= nums[p1]
            sumNum += nums[p2]
            p1 += 1
            p2 += 1
            max_sum = max(max_sum, sumNum)

        return max_sum / k
