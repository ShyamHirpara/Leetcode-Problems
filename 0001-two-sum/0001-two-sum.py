class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen = {}
        ans = []

        for i in range(0,len(nums),1): 
            if target - nums[i] in seen:
                ans.append(seen[target-nums[i]])
                ans.append(i)
                return ans
            seen[nums[i]] = i

        return ans
