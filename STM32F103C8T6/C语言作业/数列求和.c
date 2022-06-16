#include <stdio.h> 

int main()
{
	int n=0;
	int i=0;
	int sum=0;
	
	scanf("%d",&n);
	for(i=1 ; i<=n ; i++)
	{
		sum+=i;
	}
	printf("%d",sum);
	return 0; 
}
