#include <stdio.h> 

int main()
{
	int number = 0;
	int apple = 0;
	
	printf("请输入学生数量及每名学生分配到的苹果数量：");
	scanf("%d %d", &number, &apple);
	int c = number * apple; 

	printf("共%d个。\n",c);
	
	return 0; 
} 
