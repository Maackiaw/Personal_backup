#include <stdio.h> 

int main()
{
	int i = 0;
	int n = 0;
	int m = 0;
	int a[100] ;
	int count = 1;
	int temp = 0;
	scanf("%d",&n);
	
	for(i=1;n!=1;i++){
	a[i]=n;
	if (n%2==0){
		m = n/2;
		n = m;
	}else{
		m = n*3+1;
		n = m;
    }
    count++;
}
    printf("1 ");
    for(i=1;i<=count/2;i++){
    	temp = a[i];
    	a[i] = a[count-i];
    	a[count-i] = temp;
	}
	
	for(i=1;i<count;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
