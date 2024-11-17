/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <cstddef>
int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
	for (int i = 0; i < numsSize; i++)
	{
		for (int j = i + 1; j < numsSize; j++)
		{
			if ((nums[i] + nums[j]) == target)
			{
				int* arr = (int*)malloc(sizeof(int) * 2);
				arr[0] = i;
				arr[1] = j;
				*returnSize = 2;
				return arr;
			}
		}
	}
	*returnSize = 0;
	return NULL;
}