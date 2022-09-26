class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}
        for i in range(len(nums)):
            compare = target - nums[i]
            if compare in hashmap:
                return [hashmap[compare], i]
            hashmap[nums[i]] = i
