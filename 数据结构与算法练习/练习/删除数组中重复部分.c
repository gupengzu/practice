//int removeDuplicates(int* nums, int numsSize)
//{
//	for (int i = 0; i < numsSize-1; i++)
//	{
//		if (nums[i] == nums[i + 1])
//		{
//			for (int j = i; j < numsSize; j++)
//			{
//				nums[j] = nums[j + 1];
//			}
//			i--;
//			numsSize--;
//		}
//	}
//	return numsSize;
//}


//int removeDuplicates(int* nums, int numsSize)
//{
//	if (numsSize == 0)
//	{
//		return 0;
//	}
//	int i = 0;
//	for (int j = 1; j < numsSize; j++)
//	{
//		if (nums[i] != nums[j])
//		{
//			i++;
//			nums[i] = nums[j];
//		}
//	}
//	return i + 1;
//}