#include <stdio.h> 

int main()
{
	int a = 0;
	
	printf("��������ݣ�");
	scanf("%d",&a);
	
	printf("%d\n", a%4==0 & a%100!=0 |a%400==0);
	return 0;
}
