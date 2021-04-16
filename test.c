#define _CRT_SECURE_NO_WARING
#include <stdio.h>

//指针的进阶

/*
int main()
{
	int aa[2][5] = { 10,9,8,7,6,5,4,3,2,1 };
	int* ptr1 = (int*)(&aa + 1);
	int* ptr2 = (int*)(*(aa + 1));
	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1)); //1 ; 6 
	return 0;
}
*/

#include <string.h>
#include <assert.h>

//旋转字符串：实现一个函数，可以左旋字符串中的k个字符
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB
/*

//暴力求解法
//void left_move(char* arr, int k)//也可以写成:void left_move(char arr[], int k)
//{
//	
//	int i = 0;
//	assert(arr != NULL);
//	int len = strlen(arr);
//	for (i = 0; i < k; i++)
//	{
//		//左旋转一个字符
//		//1
//		char tmp = *arr;
//		//2
//		int j = 0;
//		for (j = 0; j < len - 1; j++)
//		{
//			*(arr + j) = *(arr + j + 1);
//		}
//		//3
//		*(arr + len - 1) = tmp;
//	}
//}

//三部翻转法
//ab cdef 分开逆序
//ba fedc 整体逆序
//cdefab

//逆序字符串的函数
void reverse(char* left, char* right)
{
	assert(left != NULL);
	assert(right != NULL);
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

void left_move(char* arr, int k)
{
	assert(arr);
	int len = strlen(arr);
	assert(k <= len);
	reverse(arr, arr + k - 1); //逆序左边
	reverse(arr + k, arr + len - 1); //逆序右边
	reverse(arr, arr + len - 1); //逆序整体
}

int main()
{
	char arr[] = "abcdef";
	left_move(arr, 2);

	printf("%s\n", arr);
	return 0;
}
*/



//字符串旋转结果：写一个函数，判断一个字符串是否为另一个字符串旋转之后的字符串
//例如：给定s1=AABCD和s2=BCDAA,返回1； 给定s1=abcd 和s2=ACBD ，返回0
// AABCD 左旋一个字符得到 ABCDA
// AABCD 左旋两个字符得到 BCDAA
// AABCD 右旋一个字符得到 DAABC
/*
void reverse(char* left, char* right)
{
	assert(left != NULL);
	assert(right != NULL);
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

void left_move(char* arr, int k)
{
	assert(arr);
	int len = strlen(arr);
	assert(k <= len);
	reverse(arr, arr + k - 1); 
	reverse(arr + k, arr + len - 1); 
	reverse(arr, arr + len - 1); 
}

int is_left_move(char* s1, char* s2)
{
	int len = strlen(s1);
	int i = 0;
	for (i = 0; i < len; i++)
	{
		left_move(s1, 1);
		int ret = strcmp(s1, s2);
		if (ret == 0)
		{
			return 1;
		}
	}
	return 0;
}



//方法二
//int is_left_move(char* str1, char str2)
//{
//	int len1 = strlen(str1);
//	int len2 = strlen(str2);
//	if (len1 != len2)
//		return 0;
//	//1.在str1字符串中追加一个str1字符串
//	//strcat
//	//strncat
//	strncat(str1, str1, 6); 
//	//2.判断str2指向的字符串是否是str1指向的字符串的子串
//  //strstr - 找子串的
//	char* ret = strstr(str1, str2);
//	if (ret == NULL)
//	{
//		return 0;
//	}
//	else
//		return 1;
//}


int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "cdefab";
	int ret = is_left_move(arr1, arr2);
	if (ret == 1)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
*/



//杨氏矩阵：有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的
// 请编写程序在这样的矩阵中查找某个数组是否存在
//要求：时间复杂度小于O(N);
/*
int FindNum(int arr[3][3], int k, int row, int col)
{

	int x = 0;
	int y = col - 1;
	while (x <= row - 1 && y >= 0)
	{
		if (arr[x][y] > k)
			y--;
		else if (arr[x][y] < k)
			x++;
		else
			return 1;
	}
	return 0;	
}

int main()
{
	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int k = 7;
	int ret = FindNum(arr, k, 3, 3);
	if (ret == 1)
	{
		printf("找到了\n");
	}
	else
		printf("找不到\n");
	return 0;
}
*/

//找到地址
int FindNum(int arr[3][3], int k, int* px, int* py)
{

	int x = 0;
	int y = *py - 1;
	while (x <= *px - 1 && y >= 0)
	{
		if (arr[x][y] > k)
			y--;
		else if (arr[x][y] < k)
			x++;
		else
		{
			*px = x;
			*py = y;
			return 1;
		}
			
	}
	//找不到

	return 0;
}

int main()
{
	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int k = 7;
	int x = 3;
	int y = 3;
	//返回型参数
	int ret = FindNum(arr, k, &x, &y);
	if (ret == 1)
	{
		printf("找到了\n");
		printf("下标是： %d %d\n", x, y);
	}
	else
		printf("找不到\n");
	return 0;
}


