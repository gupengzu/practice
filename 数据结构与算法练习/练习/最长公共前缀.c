//char* longestCommonPrefix(char** strs, int strsSize)
//{
//
//	char* finall = (char*)malloc(sizeof(char) *300);
//	int index = 0;
//	int min = strlen(strs[0]);
//	for (int i = 0; i < strsSize; i++)
//	{
//		if (strlen(strs[i]) < min)
//		{
//			min = strlen(strs[i]);
//		}
//	}
//	for (int j = 0; j < min; j++)
//	{
//		for (int z = 0; z < strsSize; z++)
//		{
//			if (strs[0][j] != strs[z][j])
//			{
//				finall[index] = '\0';
//				return finall;
//			}
//		}
//		finall[index] = strs[0][j];
//		index++;
//	}
//	finall[index] = '\0';
//	return finall;
//}