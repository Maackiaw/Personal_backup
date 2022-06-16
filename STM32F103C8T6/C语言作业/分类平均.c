#include <stdio.h> 

int main()
{
	int n;
	int k;
	double count1 = 0.0;
	double count2 = 0.0;
	double mark1 = 0.0;
	double mark2 = 0.0;
	scanf("%d %d" , &n , &k);
	
	int i=1;
	for( i=1 ; i<=n ; i++)
	{
		if (i%k==0)
		{
			count1 = count1+i;
			mark1 ++;
		}
		else
		{
			count2 = count2+i;
			mark2  ++;
		}
	}
	printf("%0.1f %0.1f",count1/mark1,count2/mark2);
	
	return 0;
}
