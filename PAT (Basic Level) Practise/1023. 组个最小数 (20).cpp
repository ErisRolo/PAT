#include <cstdio>

int main()
{
	int count[10]; //记录数字0-9的个数
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &count[i]);
	}
	//从1-9中选择count不为0的最小的数字
	for (int i = 1; i < 10; i++)
	{
		if (count[i]>0)
		{
			printf("%d", i);
			count[i]--;
			break; //找到一个之后就中断
		}
	}
	//从0-9输出对应个数的数字
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < count[i]; j++)
		{
			printf("%d", i);
		}
	}
    return 0;
}