//#define MAXSIZE 100 
//typedef struct
//{
//	int data[MAXSIZE];
//	int length;
//}Sqlist;
//void Initlist(Sqlist* L)
//{
//	L->length=0;
//}
//int listempty(Sqlist L)
//{
//	return L.length == 0;
//}
//int listlength(Sqlist L)
//{
//	return L.length;
//}
//int Getelem(Sqlist L,int i,int*e)
//{
//	if (i<1 || i>L.length)
//	{
//		return 0;
//	}
//	*e = L.data[i - 1];
//	return 1;
//}
//int index(Sqlist L, int e)
//{
//	int i;
//	for (i = 0; i < L.length; i++)
//	{
//		if (e == L.data[i])
//		{
//			return i+1;
//		}
//	}
//	return 0;
//}
//void insert(Sqlist*L, int i,int e)
//{
//	if (i<1 || i>L->length)
//	{
//		return 0;
//	}
//	if (L->length == MAXSIZE)
//	{
//		return 0;
//	}
//	for (int j = L->length; j > i; j--)
//	{
//		L->data[j] = L->data[j - 1];
//	}
//	L->data[i-1]=e;
//	L->length++;
//	return 1;
//}
//void delete(Sqlist* L, int i,int*e)
//{
//	if (i<1 || i>L->length)
//	{
//		return 0;
//	}
//	*e = L->data[i - 1];
//	for (int j=i;j<L->length;j++)
//	{
//		L->data[j-1] = L->data[j];
//	}
//	L->length--;
//	return 1;
//}