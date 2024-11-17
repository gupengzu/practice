//bool isPalindrome(int x)
//{
//	if (x < 0)
//	{
//		return false;
//	}
//	int count = 0;
//	int count1 = 0;
//	int count2 = 0;
//	int y = x;
//	while (y != 0)
//	{
//		y = y / 10;
//		count++;
//	}
//	int temp = count * 4 + 400;
//	int* arr = (int*)malloc(temp);
//
//	while (x != 0)
//	{
//		int a = x % 10;
//		arr[count2] = a;
//		x = x / 10;
//		count2++;
//	}
//	count2--;
//	while (count1 <= count2)
//	{
//		if (arr[count1] != arr[count2])
//		{
//			return false;
//		}
//		count1++;
//		count2--;
//	}
//	return true;
//}