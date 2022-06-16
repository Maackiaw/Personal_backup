#include <stdio.h> 

int main()
{
	int day=0;
	int i=1;
	int peach=0;
	scanf("%d",&day);
	
	while(day>1){
		peach = (i+1)*2;
		i=peach;
		day--;
	}
	printf("%d",peach);
	
	return 0;
}
