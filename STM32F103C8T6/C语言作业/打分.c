#include <stdio.h> 

int main()
{
	int n = 0;
	int i = 0;
	int t = 0;
	double sum = 0;
	while(1)
	{
		scanf("%d",&t);
		if(t<0)
		{
			break;
		}
		sum+=t;
		n++;
	}
	printf("%f",sum/n);
	
	return 0; 
}
