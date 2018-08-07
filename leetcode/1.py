'''
form a dict, once we get a number, first we check if target - number is in the dict,
if not, we put target - number to dict
'''

class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        list_size = len(nums)
        val_to_index = {}
        for i in range(list_size):
            now = nums[i]
            if val_to_index.get(target - now) == None:
                val_to_index[now] = i
            else:
                return (val_to_index[target - now], i)