#include <stdio.h> 

int main()
{
	int a[9];
	int i=0,j=0;
	int k=0;
	int num=9;
	
	for (i=0;i<=9;i++){
		a[i]=i+1;
	}
	i=0;
	for (j=1;j<=10;j++){
		if(i<=num){
			i++;
		if (j==3){
			printf("%d ",a[i]);
			j=0;	
		}
	}
	else{
		i=0;
	}
	}
	return 0;
}
