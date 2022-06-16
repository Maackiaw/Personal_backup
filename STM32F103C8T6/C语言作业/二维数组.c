#include <stdio.h> 

int main()
{
	const int size=4;
	int a[size][size];
	int i,j;
	int max=0;
	int min=1000;
	int line1=0,line2=0;
	int row1=0,row2=0;
	
	for (i=0;i<5;i++){
		for (j=0;j<5;j++){
			scanf("%d",&a[i][j]);
		} 
	}
	
	for (i=0;i<5;i++){
		for (j=0;j<5;j++){
			if (a[i][j]>max){
				max=a[i][j];
				line1=i;
				row1=j;
			}
			if (a[i][j]<min){
				min=a[i][j];
				line2=i;
				row2=j;
			}
		}
	}
	printf("max=%d ",max);
	printf("line=%d row=%d\n",line1,row1);
	printf("min=%d ",min);
	printf("line=%d row=%d\n",line2,row2);
	return 0;
 } 
